#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
	int TC, K, num, sum;
	stack<int> st;

	cin >> TC;

	for (int t = 1; t <= TC; t++)
	{
		sum = 0;

		cin >> K;
		while (K--)
		{
			cin >> num;
			if (num == 0)
			{
				st.pop();
			}
			else
			{
				st.push(num);
			}
		}
		while (!st.empty())
		{
			sum += st.top();
			st.pop();
		}
		cout << "#" << t << " " << sum << endl;
	}
}