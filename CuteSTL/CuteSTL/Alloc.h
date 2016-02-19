#ifndef _ALLOC_H_
#define _ALLOC_H_

#include<cstdlib>

//���򲻿��Ƕ��߳����
namespace CuteSTL
{
	//�ռ������������ֽ���Ϊ��λ���з���

	class alloc
	{
	private:
		enum CAlign { ALIGN = 8 };         //С��������ϵ��߽�
		enum CMaxBytes { MAXBYTES = 128 }; //С��������Ͻ�
		enum CNFreeLists { NFREELISTS = (CMaxBytes::MAXBYTES) / (CAlign::ALIGN) }; //�����������

	private:
		union obj //��������Ľڵ�
		{
			union obj *next;
			char client[1];
		};
		static obj* free_lists[CNFreeLists::NFREELISTS];

	private:
		//��bytes�ϵ���8�ı���
		static size_t ROUND_UP(size_t bytes)
		{
			return (bytes + (CAlign::ALIGN - 1))&~(CAlign::ALIGN - 1);
		}
		//���������С,����ʹ�õ�n����������,n��0����
		static size_t FREELISTS_INDEX(size_t bytes)
		{
			return (bytes + CAlign::ALIGN - 1) / CAlign::ALIGN - 1;
		}
		//���ش�СΪn�Ķ��󣬲����ܼ����СΪn���������鵽��������
		static void* refill(size_t n);
		//����һ���ռ�,������nobjs����СΪsize������
		//�������nobjs��������������,nobjs��������
		static char* chunk_alloc(size_t size, size_t& nobjs);

		//chunk allocation state
		static char* start_free; //�ڴ����ʼλ��,����chunk_alloc()�б仯
		static char* end_free;   //�ڴ����ֹλ��,����chunk_alloc()�б仯
		static size_t heap_size; 

	public:
		static void *allocate(size_t bytes);
		static void deallocate(void* ptr, size_t bytes);
		static void *reallocate(void *ptr, size_t old_sz, size_t new_sz);
	};
}

#endif // !_ALLOC_H_
