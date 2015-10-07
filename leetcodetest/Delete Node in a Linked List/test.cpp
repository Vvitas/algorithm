#include"../leetcodetest/head.h"

class Solution 
{
public:
	void deleteNode(ListNode* node) 
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

int main()
{
	return 0;
}