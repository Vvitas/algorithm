#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		set<int> data;
		ListNode *p1 = head, *pre = NULL;

		while (p1)
		{
			if (data.find(p1->val) == data.end())
			{
				data.insert(p1->val);
				pre = p1;
				p1 = p1->next;
			}
			else
			{
				pre->next = p1->next;
				delete p1;
				p1 = pre->next;
			}
		}
		return head;
	}
};

int main()
{
	return 0;
}