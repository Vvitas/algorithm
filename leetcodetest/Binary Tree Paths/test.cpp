#include"../leetcodetest/head.h"

class Solution 
{
public:
	string format(int num)
	{
		char buffer[32] = { 0 };
		sprintf(buffer, "%d", num);
		return string(buffer);
	}

	void binaryTreePaths(TreeNode* root,string str,vector<string>& result)
	{
		if (str.length() != 0)
		{
			str = str + "->" + format(root->val);
		}
		else str = format(root->val);

		if (root->left || root->right)
		{
			if (root->left)
				binaryTreePaths(root->left, str, result);
			if (root->right)
				binaryTreePaths(root->right, str, result);
		}
		else
		{
			result.push_back(str);
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		string str;
		vector<string> result;

		if (root == NULL) 
			return result;
		else
		{
			binaryTreePaths(root, str, result);
			return result;
		}
	}
};

int main()
{
	TreeNode *temp = new TreeNode(1);

	Solution test;
	cout << test.format(1) << endl;
	auto var = test.binaryTreePaths(temp);

	delete temp;
	return 0;
}