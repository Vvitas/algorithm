#include"../leetcodetest/head.h"

class Stack
{
public:
	// Push element x onto stack.
	void push(int x)
	{
		if (!qdata1.empty())
			qdata1.push(x);
		else if (!qdata2.empty())
			qdata2.push(x);
		else qdata1.push(x);
	}

	// Removes the element on top of the stack.
	void pop()
	{
		if (!qdata1.empty())
		{
			if (1 == qdata1.size())
				qdata1.pop();
			else
			{
				while (qdata1.size() != 1)
				{
					qdata2.push(qdata1.front());
					qdata1.pop();
				}
				qdata1.pop();
			}
		}
		else
		{
			if (1 == qdata2.size())
				qdata2.pop();
			else
			{
				while (qdata2.size() != 1)
				{
					qdata1.push(qdata2.front());
					qdata2.pop();
				}
				qdata2.pop();
			}
		}
	}

	// Get the top element.
	int top()
	{
		if (qdata1.empty())
			return qdata2.back();
		else return qdata1.back();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		if (qdata1.empty() && qdata2.empty())
			return true;
		else return false;
	}

private:
	queue<int> qdata1, qdata2;
};

int main()
{
	return 0;
}