/*
�ϳ��� ���鼭 visit üũ���ָ鼭 �������� ����
1�̻��� ���õǾ��� �� ���� �������� Ȯ��
����, �� �������� 2/1�� �Ѿ��ٸ� �������� ����ϸ� ��
��) 1,2,3,5 ��  1, 5�� �����̶�� 3, 5�� ���ʿ� ����ϴ� ����Ǽ�!
-> +4�� ���ָ� ��.
*/
#include <iostream>
using namespace std;

int Data[9], visit[9];
long long ans = 0;
int N, T, total;

void dfs(int cnt, int left, int right) {
	if (cnt == N) {
		ans++;
		return;
	}
	if (left > total / 2) {
		int t1 = 1, t2 = 1;
		for (int i = 1; i <= N - cnt; i++) {
			t1 *= i;
			t2 *= 2;
		}
		ans += t1*t2;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		dfs(cnt + 1, left + Data[i], right);
		if (left >= right + Data[i])
			dfs(cnt + 1, left, right + Data[i]);
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		total = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> Data[i];
			total += Data[i];
			visit[i] = 0;
		}
		dfs(0, 0, 0);
		cout << '#' << tc << ' ' << ans << '\n';
	}
}