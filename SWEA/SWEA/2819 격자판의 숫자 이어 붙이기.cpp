#include <iostream>
#include <string>
#include <set>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[4][4];
set<string> s;
string str;

int chk(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void dfs(int x, int y, string tmp, int depth) {
	tmp += map[x][y];
	if (depth == 7) {
		s.insert(tmp);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (chk(nx, ny)) {
			dfs(nx, ny, tmp, depth + 1);
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		s.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			str = "";
			for (int j = 0; j < 4; j++) {
				dfs(i, j, "", 1);
			}
		}
		cout << "#" << tc << " " << s.size() << endl;
	}
}