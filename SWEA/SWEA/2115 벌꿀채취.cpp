#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, M, C, ans, tmp;
int map[10][10], visit[10][10];

void getPrice(int x, int y, int cnt, int sum, int price) {
	if (sum > C)
		return;
	if (cnt == M) {
		tmp = max(tmp, price);
		return;
	}
	getPrice(x, y + 1, cnt + 1, sum + map[x][y], price + map[x][y] * map[x][y]);
	getPrice(x, y + 1, cnt + 1, sum, price);
}

int solve(int x, int y) {
	for (int i = 0; i < M; i++) {
		visit[x][y + i] = 1;
	}
	tmp = 0;
	getPrice(x, y, 0, 0, 0);
	int priceA = tmp;
	int priceB = 0;
	for (int i = x; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (visit[i][j])
				continue;
			tmp = 0;
			getPrice(i, j, 0, 0, 0);
			priceB = max(priceB, tmp);
		}
	}
	return priceA + priceB;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visit, 0, sizeof(visit));
		ans = 0;
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				ans = max(ans, solve(i, j));
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}
}