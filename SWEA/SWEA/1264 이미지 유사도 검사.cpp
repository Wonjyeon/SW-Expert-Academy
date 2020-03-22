#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T, table[501][501];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed;
	cout.precision(2);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		double N, MAX, LCS_length;
		string str1, str2;
		cin >> N;
		cin >> str1 >> str2;

		// string setting
		str1 = "0" + str1;
		str2 = "0" + str2;
		int len1 = str1.length();
		int len2 = str2.length();

		// table setting
		for (int i = 0; i < len1; i++)
			table[0][i] = 0;
		for (int i = 1; i < len2; i++) {
			MAX = 0;
			table[i][0] = 0;
			for (int j = 1; j < len1; j++) {
				// 같다면 MAX값 업데이트
				if (str1[j] == str2[i]) {
					table[i][j] = table[i - 1][j - 1] + 1;
					MAX = table[i][j];
				}
				else
					table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
			if (LCS_length < MAX) LCS_length = MAX;
		}
		cout << '#' << tc << ' ' << (LCS_length / N) * 100 << '\n';
	}
}