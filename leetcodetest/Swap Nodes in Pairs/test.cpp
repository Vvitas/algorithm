#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		int temp;
		ListNode *p1 = head, *p2 = head->next;

		while (p2)
		{
			temp = p1->val;
			p1->val = p2->val;
			p2->val = temp;

			if (p1 = p2->next)
				p2 = p1->next;
			else break;
		}

		return head;
	}
};

int main()
{
	return 0;
}