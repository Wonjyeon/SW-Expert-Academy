#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
	int T, N, M;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int MAX = -1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int sum = arr[i] + arr[j];
				if (sum <= M) {
					MAX = max(sum, MAX);
				}
			}
		}
		cout << "#" << tc << " " << MAX << endl;

	}
}