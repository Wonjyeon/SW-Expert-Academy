#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int main()
{
	set<string,greater<string>> s;
	int T, N, K;
	char arr[29];
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> K;
		string str = "";
		string ans = "";
		cin >> str;
		int cnt = 0;
		int num = N / 4;
		str = str.append(str);

		for (int i = 0; i < N; i++)
		{
			string str2 = str.substr(i, num);
			s.insert(str2);
		}
		for (auto it : s)
		{
			cnt++;
			if (cnt == K)
				ans = it;
		}
		s.clear();
		char cstr[8];
		strcpy(cstr, ans.c_str());
		int ten_ans = (int)strtol(cstr, NULL, 16);
		cout << "#" << tc << " " << ten_ans << endl;
	}
}