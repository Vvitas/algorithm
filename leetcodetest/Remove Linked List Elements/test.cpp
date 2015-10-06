#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == NULL)
			return head;

		ListNode *pre, *node = head, *result = head;
		if (head->val == val)
		{
			while (head && head->val == val)
			{
				node = head;
				head = head->next;
				delete node;
			}
			result = head;
		}

		while (head)
		{
			if (head->val != val)
			{
				pre = head;
				head = head->next;
			}
			else
			{
				node = head;
				pre->next = head->next;
				head = head->next;
				delete node;
			}
		}

		return result;
	}
};

int mian()
{
	return 0;
}