#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct BC {
	int x, y, c, p;
};
int T, M, A, ans;
vector<pair<int, int>> pA, pB;
vector<BC> bc;
int dx[] = { 0, 0,1,0,-1 };
int dy[] = { 0,-1,0,1,0 };

bool cmp(BC b1, BC b2) {
	return b1.p > b2.p;
}

void solve() {
	for (int i = 0; i <= M; i++) {
		int ax = pA[i].first, ay = pA[i].second;
		int bx = pB[i].first, by = pB[i].second;
		vector<pair<int, int>> vA, vB;
		for (int j = 0; j < A; j++) {
			BC now = bc[j];
			if (abs(ax - now.x) + abs(ay - now.y) <= now.c)
				vA.push_back({ j, now.p });
			if (abs(bx - now.x) + abs(by - now.y) <= now.c)
				vB.push_back({ j, now.p });
		}
		// B만 있는 경우
		if (!vA.size() && vB.size())
			ans += vB[0].second;
		// A만 있는 경우
		else if (vA.size() && !vB.size())
			ans += vA[0].second;
		// 둘 다 있는 경우
		else if (vA.size() && vB.size()) {
			int Max = 0;
			for (int a = 0; a < vA.size(); a++) {
				int tmp = 0;
				for (int b = 0; b < vB.size(); b++) {
					if (vA[a].first == vB[b].first) tmp = vA[a].second;
					else tmp = vA[a].second + vB[b].second;
					Max = max(Max, tmp);
				}
			}
			ans += Max;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		bc.clear();
		pA.clear();
		pB.clear();
		ans = 0;
		int dir;
		pA.push_back({ 1,1 });
		pB.push_back({ 10,10 });
		cin >> M >> A;
		for (int i = 1; i <= M; i++) {
			cin >> dir;
			int x = pA[i - 1].first + dx[dir];
			int y = pA[i - 1].second + dy[dir];
			pA.push_back({ x,y });
		}
		for (int i = 1; i <= M; i++) {
			cin >> dir;
			int x = pB[i - 1].first + dx[dir];
			int y = pB[i - 1].second + dy[dir];
			pB.push_back({ x,y });
		}
		for (int i = 0; i < A; i++) {
			BC b;
			cin >> b.x >> b.y >> b.c >> b.p;
			bc.push_back(b);
		}
		sort(bc.begin(), bc.end(), cmp);
		solve();

		cout << '#' << tc << ' ' << ans << '\n';
	}
}