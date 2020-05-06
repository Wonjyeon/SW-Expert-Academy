#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, ans, map[20][20], total;
vector<pair<int, int>> house;

void solution() {
	for (int k = 2; k <= N + 1; k++) {
		int cost = k*k + (k - 1)*(k - 1);
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				int sum = 0;
				for (int i = 0; i < house.size(); i++) {
					int dist = abs(x - house[i].first) + abs(y - house[i].second);
					if (dist <= k - 1)
						sum++;
				}
				if (sum * M < cost) continue;
				ans = max(ans, sum);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		ans = 1;
		house.clear();
		total = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					house.push_back({ i, j });
					total++;
				}
			}
		}
		if (total != 1)
			solution();
		cout << '#' << tc << ' ' << ans << '\n';
	}
}