#include "Alloc.h"

namespace CuteSTL
{
	char *alloc::start_free = 0;
	char *alloc::end_free = 0;
	size_t alloc::heap_size = 0;

	alloc::obj *alloc::free_lists[alloc::CNFreeLists::NFREELISTS] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	void *alloc::allocate(size_t bytes)
	{
		//大于128使用malloc,SGI STL中做法类似
		//不过其添加了malloc失败解决方案
		if (bytes > (size_t)CMaxBytes::MAXBYTES)
		{
			return malloc(bytes);
		}

		//寻找自由链表中适当的索引
		size_t index = FREELISTS_INDEX(bytes);
		obj *t_free_lists = free_lists[index];

		//如果没有找到可用的自由链表节点,重新填充自由链表
		if (0 == t_free_lists)
		{
			return refill(ROUND_UP(bytes));
		}

		//调整自由链表
		free_lists[index] = t_free_lists->next;
		return t_free_lists;
	}

	void alloc::deallocate(void *ptr, size_t bytes)
	{
		if (bytes > (size_t)CMaxBytes::MAXBYTES)
		{
			free(ptr); return; //大于128,直接销毁
		}

		size_t index = ROUND_UP(bytes);
		obj* node = static_cast<obj*>(ptr);
		node->next = free_lists[index];
		free_lists[index] = node; //此段代码的意义尚未清楚
	}

	void *alloc::reallocate(void *ptr, size_t old_sz, size_t new_sz)
	{
		deallocate(ptr, old_sz);
		return allocate(new_sz);
	}

	void *alloc::refill(size_t bytes)
	{
		size_t nobjs = 20;

		obj *result = 0;
		obj *current_obj = 0, *next_obj = 0;
		obj **my_free_list = 0;

		char *chunk = chunk_alloc(bytes, nobjs);
		if (1 == nobjs)
		{
			return chunk; //取出的空间仅够一个对象使用
		}

		//调整自由链表,引导其纳入新的节点
		my_free_list = free_lists + FREELISTS_INDEX(bytes);

		//以下在chunk空间内建立自由链表
		result = (obj *)chunk; //此块返回至客户端
		//引导自由链表指向新配置的空间
		*my_free_list = next_obj = (obj*)(chunk + bytes);
		//将自由链表的各节点串接起来
		for (size_t i = 1; ; i++) //从1开始,因为第0个返回给客户端
		{
			current_obj = next_obj;
			next_obj = (obj*)((char*)next_obj + bytes);
			if (nobjs - 1 == i)
			{
				current_obj->next = 0; break;
			}
			else
			{
				current_obj->next = next_obj;
			}
		}
		return result;
	}

	//假设bytes已经上调至8的倍数
	char* alloc::chunk_alloc(size_t bytes, size_t& nobjs)
	{
		char *result = 0;
		size_t total_bytes = bytes*nobjs;
		size_t bytes_left = end_free - start_free; //内存池剩余空间

		if (bytes_left >= total_bytes) //内存池剩余空间满足需求
		{
			result = start_free;
			start_free += total_bytes;
			return result;
		}
		else if (bytes_left >= bytes) //内存池剩余空间不能完全满足需求量,但足够供应一个以上区块
		{
			nobjs = bytes_left / bytes;
			total_bytes = nobjs*bytes;
			result = start_free;
			start_free += total_bytes;
			return result;
		}
		else //内存池剩余空间严重不足
		{
			size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
			if (bytes_left > 0) //利用内存池的剩余空间
			{
				obj** my_free_list = free_lists + FREELISTS_INDEX(bytes_left);
				((obj*)start_free)->next = *my_free_list;
				*my_free_list = (obj*)start_free;
			}
			start_free = (char*)malloc(bytes_to_get);
			if (!start_free)
			{
				obj** my_free_list = 0, *p = 0;
				for (int i = 0;i < CMaxBytes::MAXBYTES;i+=CAlign::ALIGN)
				{
					my_free_list = free_lists + FREELISTS_INDEX(i);
					p = *my_free_list;
					if (0 != p)
					{
						*my_free_list = p->next;
						start_free = (char*)p;
						end_free = start_free + i;
						//递归调用自己，以便修正nobjs
						return chunk_alloc(bytes, nobjs);
					}
				}
				end_free = 0;
			}
			heap_size += bytes_to_get;
			end_free = start_free + bytes_to_get;
			return chunk_alloc(bytes, nobjs);
		}
	}
}