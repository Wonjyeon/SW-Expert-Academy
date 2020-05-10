#include <iostream>
#include <algorithm>
using namespace std;

int T, N, X, map[20][20];

int solution() {
	int ans = 0;
	// �� �������� count.
	for (int i = 0; i < N; i++) {
		int prev = map[i][0];
		int cnt = 0;
		int flag = 2;
		int k = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == prev) {
				cnt++;
				if (cnt == N) {
					ans++;
					break;
				}
			}
			// ���簡 �������� 1�� ���� ���
			else if (prev - map[i][j] == 1) {
				flag = -1;
				prev = map[i][j];
				cnt = 0;
				int cnt2 = 1;
				for (k = j + 1; k < N; k++) {
					if (map[i][k] != map[i][j]) break;
					cnt2++;
				}
				// ���̰� X���� ª�ٸ� ���θ� ���� �� ����.
				if (cnt2 < X)
					break;
				if (k == N || (k == N - 1 && map[i][k] == prev)) {
					ans++;
					break;
				}
				else
					j--;
			}
			// ���簡 �������� 1�� ���� ���
			else if (prev - map[i][j] == -1) {
				if ((flag == -1 && cnt < 2 * X) || cnt < X) break;
				prev = map[i][j];
				flag = 1;
				j--;
				cnt = 0;
			}
			// �װ͵� �ƴ϶�� ��������.
			else
				break;
			if (j == N - 1) ans++;
		}
	}
	// �� �������� count.
	for (int i = 0; i < N; i++) {
		int prev = map[0][i];
		int cnt = 0;
		int k = 0;
		int flag = 2;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == prev) {
				cnt++;
				if (cnt == N) {
					ans++;
					break;
				}
			}
			// ���簡 �������� 1�� ���� ���
			else if (prev - map[j][i] == 1) {
				flag = -1;
				prev = map[j][i];
				cnt = 0;
				int cnt2 = 1;
				for (k = j + 1; k < N; k++) {
					if (map[k][i] != map[j][i]) break;
					cnt2++;
				}
				// ���̰� X���� ª�ٸ� ���θ� ���� �� ����.
				if (cnt2 < X)
					break;
				if (k == N || (k == N - 1 && map[k][i] == prev)) {
					ans++;
					break;
				}
				else
					j--;
			}
			// ���簡 �������� 1�� ���� ���
			else if (prev - map[j][i] == -1) {
				if ((flag == -1 && cnt < 2 * X) || cnt < X) break;
				prev = map[j][i];
				cnt = 0;
				flag = 1;
				j--;
			}
			// �װ͵� �ƴ϶�� ��������.
			else
				break;
			if (j == N - 1) ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		cout << '#' << tc << ' ' << solution() << '\n';
	}
}