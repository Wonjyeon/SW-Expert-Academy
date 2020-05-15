#include <iostream>
#include <algorithm>
using namespace std;

int T, N, ans, sx, sy, map[21][21];
bool visit[101];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

void dfs(int c, int r, int dir, int cnt) {
	visit[map[c][r]] = true;
	int x = c + dx[dir], y = r + dy[dir];
	// ������ �����̸鼭 ó�� ������ ����. -> ������ ��Ʈ.
	if (dir == 3 && x == sx&&y == sy) {
		ans = max(ans, cnt);
		visit[map[c][r]] = false;
		return;
	}
	// ���� �ȿ� �����鼭 ���� ���� ���� ����Ʈ
	if (x >= 0 && x < N&&y >= 0 && y < N && !visit[map[x][y]]) {
		// �ִ��� �� �������� �� ��
		dfs(x, y, dir, cnt + 1);
		// ���� ������ ������ �ʾҰ�, �� ���� �������� ����.
		if (dir < 3)
			dfs(x, y, dir + 1, cnt + 1);
	}
	visit[map[c][r]] = false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		ans = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		for (int i = 0; i < N - 2; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i, sy = j;
				dfs(i, j, 0, 1);
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}