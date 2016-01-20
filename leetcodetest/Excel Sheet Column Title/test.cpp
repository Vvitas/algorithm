#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string res="";
		while (n)
		{
			res = char((n - 1) % 26 + 'A') + res;
			n = (n - 1) / 26;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	cout << sol.convertToTitle(1) << endl;
	cout << sol.convertToTitle(27) << endl;
	return 0;
}