#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *ReverseHead = NULL;
		ListNode *pre = NULL, *curr = head, *next = NULL;

		while (curr)
		{
			next = curr->next;

			if (next == NULL)
				ReverseHead = curr;
			curr->next = pre;

			pre = curr;
			curr = next;
		}

		return ReverseHead;
	}
};

int main()
{
	return 0;
}