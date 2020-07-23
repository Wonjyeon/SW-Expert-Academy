#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pa;
struct BC {
	int x, y, c, p;
};
int T, M, A, dir, ans = 0;
int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };
pa pA[101], pB[101];
BC battery[8];

bool cmp(int a, int b) {
	return battery[a].p > battery[b].p;
}

void solve() {
	for (int i = 0; i <= M; i++) {
		int aX = pA[i].first, aY = pA[i].second;
		int bX = pB[i].first, bY = pB[i].second;
		vector<int> vA, vB;

		for (int j = 0; j < A; j++) {
			BC nowBC = battery[j];
			int distA = abs(aX - nowBC.x) + abs(aY - nowBC.y);
			int distB = abs(bX - nowBC.x) + abs(bY - nowBC.y);
			if (distA <= nowBC.c)
				vA.push_back(j);
			if (distB <= nowBC.c)
				vB.push_back(j);
		}
		sort(vA.begin(), vA.end(), cmp);
		sort(vB.begin(), vB.end(), cmp);
		if (vA.size() > 0 && vB.size() == 0)
			ans += battery[vA[0]].p;
		else if (vA.size() == 0 && vB.size() > 0)
			ans += battery[vB[0]].p;
		else if (vA.size() > 0 && vB.size() > 0) {
			int Max = 0;
			for (int a = 0; a < vA.size(); a++) {
				for (int b = 0; b < vB.size(); b++) {
					int tmp = 0;
					if (vA[a] == vB[b]) 
						tmp = battery[vA[a]].p;
					else 
						tmp = battery[vA[a]].p + battery[vB[b]].p;
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
	pA[0] = { 1,1 };
	pB[0] = { 10,10 };
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		cin >> M >> A;
		for (int i = 1; i <= M; i++) {
			cin >> dir;
			pA[i] = { pA[i - 1].first + dx[dir], pA[i - 1].second + dy[dir] };
		}
		for (int i = 1; i <= M; i++) {
			cin >> dir;
			pB[i] = { pB[i - 1].first + dx[dir], pB[i - 1].second + dy[dir] };
		}
		for (int i = 0; i < A; i++) {
			cin >> battery[i].x >> battery[i].y >> battery[i].c >> battery[i].p;
		}
		solve();
		cout << '#' << tc << ' ' << ans << '\n';
	}
}
