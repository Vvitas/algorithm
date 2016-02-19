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
		//����128ʹ��malloc,SGI STL����������
		//�����������mallocʧ�ܽ������
		if (bytes > (size_t)CMaxBytes::MAXBYTES)
		{
			return malloc(bytes);
		}

		//Ѱ�������������ʵ�������
		size_t index = FREELISTS_INDEX(bytes);
		obj *t_free_lists = free_lists[index];

		//���û���ҵ����õ���������ڵ�,���������������
		if (0 == t_free_lists) 
		{
			return refill(ROUND_UP(bytes));
		}

		//������������
		free_lists[index] = t_free_lists->next;
		return t_free_lists;
	}
}