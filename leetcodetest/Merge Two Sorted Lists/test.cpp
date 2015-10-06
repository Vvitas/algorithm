#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL) return l2;
		else if (l2 == NULL) return l1;

		ListNode *result, *p;

		if (l1->val < l2->val)
		{
			result = p = l1;
			l1 = l1->next;
		}
		else
		{
			result = p = l2;
			l2 = l2->next;
		}

		while (l1&&l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}

		if (l1)
			p->next = l1;
		else p->next = l2;

		return result;
	}
};

int main()
{
	return 0;
}