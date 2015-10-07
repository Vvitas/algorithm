#include"../leetcodetest/head.h"

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL || l2 == NULL) return NULL;

		int val, carry = 0;
		ListNode *result = new ListNode(0);
		ListNode *NodeTmp = result;

		while (l1 || l2)
		{
			val = 0;

			if (l1)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				val += l2->val;
				l2 = l2->next;
			}

			val += carry;
			carry = val / 10;
			NodeTmp->next = new ListNode(val % 10);
			NodeTmp = NodeTmp->next;
		}

		if (carry)
			NodeTmp->next = new ListNode(1);

		NodeTmp = result;
		result = result->next;
		delete NodeTmp;
		return result;
	}
};

int main()
{
	return 0;
}