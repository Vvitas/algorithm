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

	void alloc::deallocate(void *ptr, size_t bytes)
	{
		if (bytes > (size_t)CMaxBytes::MAXBYTES)
		{
			free(ptr); return; //����128,ֱ������
		}

		size_t index = ROUND_UP(bytes);
		obj* node = static_cast<obj*>(ptr);
		node->next = free_lists[index];
		free_lists[index] = node; //�˶δ����������δ���
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
			return chunk; //ȡ���Ŀռ����һ������ʹ��
		}

		//������������,�����������µĽڵ�
		my_free_list = free_lists + FREELISTS_INDEX(bytes);

		//������chunk�ռ��ڽ�����������
		result = (obj *)chunk; //�˿鷵�����ͻ���
		//������������ָ�������õĿռ�
		*my_free_list = next_obj = (obj*)(chunk + bytes);
		//����������ĸ��ڵ㴮������
		for (size_t i = 1; ; i++) //��1��ʼ,��Ϊ��0�����ظ��ͻ���
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