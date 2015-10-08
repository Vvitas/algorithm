#include"../leetcodetest/head.h"

class Solution 
{
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		map<int, int> data;
		map<int, int>::iterator itr;
		ListNode *node = head, *delnode;
		
		while (node)
		{
			if (data.find(node->val) == data.end())
			{
				data.insert(make_pair(node->val, 1));
			}
			else data.erase(node->val);

			node = node->next;
		}


		node = head;
		for (itr = data.begin(); itr != data.end(); itr++)
		{
			node->val = itr->first;
			node = node->next;
		}
		while (node)
		{
			delnode = node;
			node = node->next;
			delete delnode;
		}

		if (data.empty())
			return NULL;
		else return head;
	}
};

int main()
{
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(1);
	ListNode *t3 = new ListNode(2);
	t1->next = t2; t2->next = t3;

	Solution test;
	test.deleteDuplicates(t1);
	delete t1, t2, t3;

	return 0;
}