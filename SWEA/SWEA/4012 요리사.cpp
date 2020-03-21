#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, ans;
int map[16][16], visit[16];

void calc() {
	int first = 0, second = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (visit[i] && visit[j])
				first += map[i][j];
			else if (!visit[i] && !visit[j])
				second += map[i][j];
		}
	}
	ans = min(ans, abs(first - second));
}

void solve(int idx, int cnt) {
	if (cnt == N / 2) {
		calc();
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visit[i])
			continue;
		visit[i] = 1;
		solve(i, cnt + 1);
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 987654321;
		memset(visit, 0, sizeof(visit));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		solve(0, 0);
		cout << "#" << tc << " " << ans << endl;
	}
}