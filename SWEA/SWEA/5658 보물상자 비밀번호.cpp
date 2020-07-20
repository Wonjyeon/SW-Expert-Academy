#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, K, ans;
string str;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<string> v;
		cin >> N >> K >> str;
		int len = N / 4;
		ans = 0;
		str += str.substr(0, len - 1);

		for (int i = 0; i <= str.length() - len; i++) {
			v.push_back(str.substr(i, len));
		}
		sort(v.rbegin(), v.rend());
		v.erase(unique(v.begin(), v.end()), v.end());
		string ans_str = v[K - 1];

		for (int i = 0; i < len; i++) {
			char c = ans_str[i];
			if (c - '0' >= 0 && c - '0' <= 9)
				ans += pow(16, (len - i - 1)) * (c - '0');
			else
				ans += pow(16, (len - i - 1)) * (c - '7');
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}
