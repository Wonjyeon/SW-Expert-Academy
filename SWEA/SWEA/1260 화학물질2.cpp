#include <iostream>
using namespace std;

int map[100][100];
int arr[100], cnt[100];
int D[21];
int DP[20][20];
int T, N;

int solve(int i, int j) {
	int Min = 987654321;
	if (DP[i][j] >= 0) return DP[i][j];
	for (int k = i; k <= j - 1; k++) {
		int t = solve(i, k) + solve(k + 1, j) + D[i] * D[k + 1] * D[j + 1];
		if (Min > t) Min = t;
	}
	return DP[i][j] = Min;
}

void dfs(int x, int y) {
	int tx = x, ty = y, r = 0, c = 0;
	// 青贸府
	while (tx < N) {
		if (map[tx][y] == 0) break;
		tx++; c++;
	}
	// 凯贸府
	while (ty < N) {
		if (map[x][ty] == 0) break;
		ty++; r++;
	}
	for (int i = x; i < x + c; i++)
		for (int j = y; j < y + r; j++)
			map[i][j] = 0;
	arr[c] = r;
	cnt[c]++; cnt[r]--;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int front, rear;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j] != 0)
					dfs(i, j);
		for (int i = 0; i < N; i++) {
			if (cnt[i] == 1) front = i;
			if (cnt[i] == -1) rear = i;
			cnt[i] = 0;
		}
		int idx = 0;
		while (1) {
			D[idx] = front;
			if (front == rear) break;
			front = arr[front];
			idx++;
		}
		for (int i = 0; i < idx; i++)
			for (int j = i + 1; j < idx; j++)
				DP[i][j] = -1;
		for (int i = 0; i < idx; i++)
			DP[i][i] = 0;
		cout << '#' << tc << ' ' << solve(0, idx - 1) << '\n';
	}
}