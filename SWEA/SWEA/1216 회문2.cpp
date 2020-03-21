#include <iostream>
#include <algorithm>
using namespace std;

char map[100][100];


int main() {
	int t;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> t;
		int result = 0;
		int m = 1;


		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}

		// 행에서 회문 구하기
		// 행
		for (int i = 0; i < 100; i++) {
			// 열
			for (int j = 0; j < 100; j++) {
				int f = j;
				int temp = 99;
				int b = temp;
				while (1) {
					if (f >= b) {
						result = temp - j + 1;
						m = max(m, result);
						break;
					}
					if (map[i][f] != map[i][b]) {
						temp--;
						b = temp;
						f = j;
					}
					else {
						f++; b--;
					}
				}
			}
		}

		// 열에서 회문 구하기
		// 열
		for (int i = 0; i < 100; i++) {
			// 행
			for (int j = 0; j < 100; j++) {
				int f = j;
				int temp = 99;
				int b = temp;
				while (1) {
					if (f >= b) {
						result = temp - j + 1;
						m = max(m, result);
						break;
					}
					if (map[f][i] != map[b][i]) {
						temp--;
						b = temp;
						f = j;
					}
					else {
						f++; b--;
					}
				}
			}
		}
		cout << "#" << t << " " << m << endl;
	}
}