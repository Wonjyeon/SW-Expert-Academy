#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };
int T, H, W, ans, d[1000][1000];
int map[1000][1000];
queue<pair<int, int>> q;

int chk(int x, int y) {
	return x >= 0 && x < H&&y >= 0 && y < W;
}

void solve() {
	int size = q.size();
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk(nx, ny) && map[nx][ny] > 0) {
				map[nx][ny]--;
				if (map[nx][ny] == 0) {
					q.push({ nx,ny });
				}
			}
		}
		if (size == cnt) {
			cnt = 0;
			size = q.size();
			if (size > 0)
				ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		string s;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			cin >> s;
			for (int j = 0; j < W; j++) {
				if (s[j] == '.') {
					map[i][j] = 0;
					q.push({ i,j });
				}
				else
					map[i][j] = s[j] - '0';
			}
		}
		solve();

		cout << "#" << tc << " " << ans << endl;
	}
}