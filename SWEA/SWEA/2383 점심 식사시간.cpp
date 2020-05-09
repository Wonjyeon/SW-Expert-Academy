#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people {
	int x, y, distA, distB;
};
struct stair {
	int x, y, t;
};
people pe[10];
stair st[2];
int T, N, ans, pe_cnt, st_cnt;

int lunchTime(vector<int> v, int t) {
	if (v.size() == 0) return 0;
	sort(v.begin(), v.end());
	int use[3] = { 0, };
	int time = v[0];

	while (1) {
		for (int i = 0; i < v.size(); i++) {
			if (!v[i]) continue;
			if (v[i] <= time) {
				for (int j = 0; j < 3; j++) {
					if (use[j] <= 0) {
						use[j] = t;
						v[i] = 0;
						if (i == v.size() - 1) return time + t;
						break;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
			use[i]--;
		time++;
	}
}

void dfs(vector<int> &A, vector<int> &B, int cnt) {
	if (cnt == pe_cnt) {
		ans = min(ans, max(lunchTime(A, st[0].t), lunchTime(B, st[1].t)));
		return;
	}
	A.push_back(pe[cnt].distA);
	dfs(A, B, cnt + 1);
	A.pop_back();
	B.push_back(pe[cnt].distB);
	dfs(A, B, cnt + 1);
	B.pop_back();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 987654321;
		pe_cnt = 0, st_cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int num;
				cin >> num;
				if (num == 1)
					pe[pe_cnt].x = i, pe[pe_cnt++].y = j;
				else if (num > 1)
					st[st_cnt].x = i, st[st_cnt].y = j, st[st_cnt++].t = num;
			}
		}
		for (int i = 0; i < pe_cnt; i++) {
			pe[i].distA = abs(pe[i].x - st[0].x) + abs(pe[i].y - st[0].y);
			pe[i].distB = abs(pe[i].x - st[1].x) + abs(pe[i].y - st[1].y);
		}
		vector<int> stairA, stairB;
		dfs(stairA, stairB, 0);
		cout << '#' << tc << ' ' << ans + 1 << '\n';
	}
}