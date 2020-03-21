#include <iostream>
#include <vector>
using namespace std;

int arr[100][2] = { -1 };
int visit[100] = { 0, };
int check = 0;
int N;

void dfs(int x) {
	if (check == 1)
		return;
	visit[x] = 1;
	for (int i = 0; i < 2; i++) {
		int nx = arr[x][i];
		if (nx == -1)
			continue;
		if (nx == 99) {
			check = 1;
			return;
		}
		if (!visit[nx] && arr[nx][0] != -1)
			dfs(nx);
	}
}

int main() {
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> t >> N;
		check = 0;


		for (int i = 0; i < 100; i++) {
			visit[i] = 0;
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 2; j++) {
				arr[i][j] = -1;
			}
		}

		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			if (arr[x][0] == -1)
				arr[x][0] = y;
			else
				arr[x][1] = y;
		}
		dfs(0);
		if (check == 1) {
			cout << "#" << t << " " << 1 << endl;
		}
		else
			cout << "#" << t << " " << 0 << endl;
	}
}