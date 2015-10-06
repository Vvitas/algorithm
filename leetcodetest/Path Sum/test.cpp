#include"../leetcodetest/head.h"

class Solution
{
private:
	//�˴�curr�������Ϊint& curr,ʼ�ղ���ac,�мǴ���
	bool judgePathSum(TreeNode* root, int sum, int curr = 0)
	{
		if (root == NULL) return false;

		curr += root->val;
		if (root->left == NULL&&root->right == NULL)
			if (curr == sum)
				return true;

		return judgePathSum(root->left, sum, curr) || judgePathSum(root->right, sum, curr);
	}

public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		return judgePathSum(root, sum);
	}
};

int main()
{
	return 0;
}