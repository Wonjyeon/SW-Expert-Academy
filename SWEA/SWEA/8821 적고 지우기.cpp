#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		int ans = 0;
		vector<int> cnt(10);
		string strNum;

		cin >> strNum;
		for (int i = 0; i < strNum.length(); i++)
		{
			cnt[strNum[i] - '0'] += 1;
		}
		for (int i = 0; i < 10; i++)
		{
			if (cnt[i] % 2 == 1)
				ans++;
		}
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}