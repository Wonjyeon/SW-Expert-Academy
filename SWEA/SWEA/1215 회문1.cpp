#include <iostream>
using namespace std;


int main() {
	int N, check = 0, cnt = 0;
	char arr[8][8];
	char arr2[8][8];

	for (int t = 1; t <= 10; t++) {
		cin >> N;
		cnt = 0;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - N; j++) {
				check = 1;
				int f = j, b = N - 1 + j;
				while (f <= b) {
					if (arr[i][f] != arr[i][b]) {
						check = 0;
						break;
					}
					f++;
					b--;
				}
				if (check == 1) {
					cnt++;
				}
			}
		}
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i <= 8 - N; i++) {
				check = 1;
				int f = i, b = N - 1 + i;
				while (f <= b) {
					if (arr[f][j] != arr[b][j]) {
						check = 0;
						break;
					}
					f++;
					b--;
				}
				if (check == 1) {
					cnt++;
				}
			}
		}
		cout << "#" << t << " " << cnt << "\n";
	}
}