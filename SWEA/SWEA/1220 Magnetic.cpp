#include <iostream>
using namespace std;

int N;
int map[100][100];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			int check = 0;
			for (int i = 0; i < N; i++) {
				if (map[i][j] == 1)
					check = 1;
				else if (map[i][j] == 2 && check) {
					cnt++;
					check = 0;
				}
			}
		}
		cout << "#" << tc << " " << cnt << endl;
	}
}