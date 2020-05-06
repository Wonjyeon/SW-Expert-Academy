#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, W, H, ans = 180;
int map[15][12];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int index(int w) {
	for (int i = 0; i < H; i++) {
		if (map[i][w] > 0)
			return i;
	}
	return -1;
}

void bfs(int X, int Y) {
	queue<pair<int, int>> q;
	q.push({ X, Y });
	bool visit[15][12];
	memset(visit, false, sizeof(visit));
	visit[X][Y] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		int n = map[x][y];
		map[x][y] = 0;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x, ny = y;
			for (int k = 0; k < n - 1; k++) {
				nx += dx[i], ny += dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) break;
				if (visit[nx][ny]) continue;
				if (map[nx][ny] == 1) map[nx][ny] = 0;
				if (map[nx][ny] > 1) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	// 벽돌 삭제 후 재정리.
	for (int j = 0; j < W; j++) {
		int idx = H;
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j] == 0) {
				idx = i;
				break;
			}
		}
		// 해당 열은 모두 벽돌. --> 재정리할 필요 없음.
		if (idx == H) continue;
		int tmp = idx;
		for (int i = tmp - 1; i >= 0; i--) {
			if (map[i][j] > 0) {
				map[idx][j] = map[i][j];
				map[i][j] = 0;
				idx--;
			}
		}
	}
}

void dfs(int depth) {
	if (depth == N) {
		int sum = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] > 0) sum++;
			}
		}
		ans = min(ans, sum);
		return;
	}
	// 현재 배열 상태를 저장함. 선택 전으로 되돌리기 위함.
	int temp[15][12];
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			temp[i][j] = map[i][j];
	int idx;
	int cnt = 0;
	for (int i = 0; i < W; i++) {
		idx = index(i);
		// 해당 열은 선택할 벽돌이 없음.
		if (idx < 0) {
			cnt++;
			continue;
		}
		cnt = 0;
		bfs(idx, i);
		dfs(depth + 1);
		// 해당 벽돌 선택 전으로 되돌림.
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				map[i][j] = temp[i][j];
	}
	// 모든 열에 대해 선택할 벽돌이 없었음.
	if (cnt == W) {
		ans = 0;
		return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> W >> H;
		ans = 180;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		dfs(0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}