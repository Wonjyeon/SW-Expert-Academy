#include <iostream>
using namespace std;


int map[50][50];

int main() {
	int N, ans = 0;
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
				if (i == N / 2) {
					ans += map[i][j];
				}
			}
		}
		int mid = N / 2;
		for (int i = 1; i <= mid; i++) {
			for (int j = i; j < N - i; j++) {
				ans += map[mid - i][j];
				ans += map[mid + i][j];
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}
}