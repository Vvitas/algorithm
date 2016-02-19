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
}