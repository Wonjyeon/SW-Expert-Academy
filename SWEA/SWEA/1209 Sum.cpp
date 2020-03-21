#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int tc;
		int row = 0;		// 열
		int col = 0;		// 행
		int dia1 = 0;		// 대각선1
		int dia2 = 0;		// 대각선2
		int m1 = 0;
		int m = 0;

		int graph[100][100];
		cin >> tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				col += graph[i][j];
				row += graph[j][i];
				if (i == j)
					dia1 += graph[i][j];
				else if (i + j == 99)
					dia2 += graph[i][j];
			}
			m1 = max(row, col);
			row = 0;
			col = 0;
			m = max(m, m1);
		}
		m = max(m, dia1);
		m = max(m, dia2);
		printf("#%d %d\n", tc, m);
	}
}