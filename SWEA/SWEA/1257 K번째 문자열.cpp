#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, K;
string str;

void suffix_Array() {
	string suffix[401];
	int lcp[401];
	int length = str.length();
	for (int i = 0; i < length; i++) {
		suffix[i] = str.substr(i, length - i);
	}
	sort(suffix, suffix + length);
	lcp[0] = 0;
	for (int i = 1; i < length; i++) {
		int m = min(suffix[i].length(), suffix[i - 1].length());
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (suffix[i][j] != suffix[i - 1][j])
				break;
			cnt++;
		}
		lcp[i] = cnt;
	}
	int count = 0;
	for (int i = 0; i < length; i++) {
		count += suffix[i].length() - lcp[i];
		if (count >= K) {
			cout << suffix[i].substr(0, suffix[i].length() - (count - K)) << '\n';
			return;
		}
	}
	cout << "none\n";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K >> str;
		cout << '#' << tc << ' ';
		suffix_Array();
	}
}