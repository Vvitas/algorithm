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
}