#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* sortList(ListNode* head)
	{
		if (head == NULL) return NULL;

		ListNode *p1 = head, *p2;
		vector<int> vtListData;

		//遍历链表,时间复杂度O(n)
		while (p1)
		{
			vtListData.push_back(p1->val);
			p1 = p1->next;
		}
		//严格意义上sort函数时间复杂度优于O(n)
		sort(vtListData.begin(), vtListData.end());

		//串联链表,时间复杂度O(n)
		p1 = head;
		for (size_t i = 0; i < vtListData.size(); i++, p1 = p1->next)
		{
			p1->val = vtListData[i];
		}

		return head;
	}
};

int main()
{
	return 0;
}