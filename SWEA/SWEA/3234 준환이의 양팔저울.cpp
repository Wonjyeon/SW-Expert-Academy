/*
하나씩 보면서 visit 체크해주면서 왼쪽으로 누적
1이상이 선택되었을 떄 왼쪽 누적값을 확인
만약, 총 누적값의 2/1이 넘었다면 나머지는 계산하면 됨
예) 1,2,3,5 중  1, 5가 왼쪽이라면 3, 5를 두쪽에 배분하는 경우의수!
-> +4를 해주면 됨.
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