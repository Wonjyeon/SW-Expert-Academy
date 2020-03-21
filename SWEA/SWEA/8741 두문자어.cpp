#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		string str[3];
		for (int i = 0; i < 3; i++)
		{
			cin >> str[i];
			str[i][0] = str[i][0] - 32;
		}
		cout << "#" << tc << " " << str[0][0] << str[1][0] << str[2][0] << endl;
	}
}