#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Arr {
	int col = 0;
	int row = 0;
};
int n, idx, map[100][100];
Arr result[20];

bool cmp(Arr a, Arr b) {
	if (a.col*a.row < b.col*b.row)
		return true;
	if (a.col*a.row == b.col*b.row) {
		if (a.col < b.col)
			return true;
	}
	return false;
}

void dfs(int x, int y) {
	int r = 0, c = 0, tx = x, ty = y;
	while (1) {
		if (map[tx][y] == 0 || tx == n)
			break;
		c++;
		tx++;
	}
	while (1) {
		if (map[x][ty] == 0 || ty == n)
			break;
		r++;
		ty++;
	}
	result[idx].col = c;
	result[idx].row = r;
	idx++;
	for (int i = x; i < x + c; i++)
		for (int j = y; j < y + r; j++)
			map[i][j] = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(result, 0, sizeof(result));
		int group_cnt = 0;
		idx = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0) {
					group_cnt++;
					dfs(i, j);
				}
			}
		}
		sort(result, result + idx, cmp);
		cout << '#' << tc << ' ' << group_cnt << ' ';
		for (int i = 0; i < idx; i++)
			cout << result[i].col << ' ' << result[i].row << ' ';
		cout << '\n';
	}
}