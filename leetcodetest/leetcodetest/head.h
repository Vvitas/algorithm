#pragma once

#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};