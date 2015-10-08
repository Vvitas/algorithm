#include"../leetcodetest/head.h"

class MinStack {
public:
	void push(int x) 
	{
		sdata.push(x);
		if (Mindata.empty())
		{
			Mindata.push(x);
		}
		else
		{
			Mindata.push(x < Mindata.top() ? x : Mindata.top());
		}
	}

	void pop() 
	{
		sdata.pop();
		Mindata.pop();
	}

	int top() 
	{
		return sdata.top();
	}

	int getMin() 
	{
		return Mindata.top();
	}

private:
	stack<int> sdata, Mindata;
};

int main()
{
	return 0;
}