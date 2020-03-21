#include <iostream>
#include <algorithm>
using namespace std;

int N = 0, result = 0;
int col[10];

bool promising(int i) {
	for (int j = 0; j < i; j++) {
		if (col[i] == col[j] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}

void N_Queen(int i) {
	if (i == N)
		result += 1;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;
			if (promising(i))
				N_Queen(i + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < N; i++) {
			col[i] = 0;
		}
		result = 0;
		cin >> N;
		N_Queen(0);
		cout << "#" << tc << " " << result << '\n';
	}
	return 0;
}