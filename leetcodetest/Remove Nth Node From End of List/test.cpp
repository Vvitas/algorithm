#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head == NULL || n < 1) return head;

		ListNode *fast = head, *slow = head, *node = NULL, *pre = NULL;
		while (n > 0 && fast)
		{
			--n;
			if (fast != NULL)
			{
				fast = fast->next;
			}
			else break;
		}

		if (fast == NULL && 0 == n) //É¾³ýÍ·½Úµã
		{
			node = head;
			head = head->next;
			delete node;
			return head;
		}

		while (fast)
		{
			fast = fast->next;
			pre = slow;
			slow = slow->next;
		}
		pre->next = slow->next;
		delete slow;

		return head;
	}
};

int main()
{
	return 0;
}