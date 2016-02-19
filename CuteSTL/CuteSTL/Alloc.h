#ifndef _ALLOC_H_
#define _ALLOC_H_

#include<cstdlib>

//程序不考虑多线程情况
namespace CuteSTL
{
	//空间配置器，以字节数为单位进行分配

	class alloc
	{
	private:
		enum CAlign { ALIGN = 8 };         //小型区块的上调边界
		enum CMaxBytes { MAXBYTES = 128 }; //小型区块的上界
		enum CNFreeLists { NFREELISTS = (CMaxBytes::MAXBYTES) / (CAlign::ALIGN) }; //自由链表个数

	private:
		union obj //自由链表的节点
		{
			union obj *next;
			char client[1];
		};
		static obj* free_lists[CNFreeLists::NFREELISTS];

	private:
		//将bytes上调至8的倍数
		static size_t ROUND_UP(size_t bytes)
		{
			return (bytes + (CAlign::ALIGN - 1))&~(CAlign::ALIGN - 1);
		}
		//根据区块大小,决定使用第n号自由链表,n从0起算
		static size_t FREELISTS_INDEX(size_t bytes)
		{
			return (bytes + CAlign::ALIGN - 1) / CAlign::ALIGN - 1;
		}
		//返回大小为n的对象，并可能加入大小为n的其他区块到自由链表
		static void* refill(size_t n);
		//配置一大块空间,可容纳nobjs个大小为size的区块
		//如果配置nobjs个区块有所不便,nobjs数量降低
		static char* chunk_alloc(size_t size, size_t& nobjs);

		//chunk allocation state
		static char* start_free; //内存池起始位置,仅在chunk_alloc()中变化
		static char* end_free;   //内存池终止位置,仅在chunk_alloc()中变化
		static size_t heap_size; 

	public:
		static void *allocate(size_t bytes);
		static void deallocate(void* ptr, size_t bytes);
		static void *reallocate(void *ptr, size_t old_sz, size_t new_sz);
	};
}

#endif // !_ALLOC_H_
