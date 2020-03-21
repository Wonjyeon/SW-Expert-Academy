#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string NUM[] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };
int cnt[10];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, N, tc_n;
	char c;
	string str;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(cnt, 0, sizeof(cnt));
		cin >> c >> tc_n >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			for (int i = 0; i < 10; i++) {
				if (str == NUM[i]) {
					cnt[i]++;
					break;
				}
			}
		}
		cout << '#' << tc << '\n';
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << NUM[i] << ' ';
			}
		}
		cout << '\n';
	}
}