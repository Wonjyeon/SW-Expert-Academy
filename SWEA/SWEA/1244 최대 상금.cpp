#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int K, ans = 0;
string str;
int D[1000000];

void solve(string s, int cnt) {
	int ret = stoi(s);
	if (D[cnt] > ret)
		return;
	D[cnt] = ret;
	if (cnt == K) {
		ans = ret;
		return;
	}

	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			string tmp = s;
			swap(tmp[i], tmp[j]);
			solve(tmp, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		memset(D, -1, sizeof(D));
		cin >> str >> K;
		solve(str, 0);
		cout << "#" << tc << " " << ans << endl;
	}
}