#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int x;
	int y;
	int num;
	int dir;
};

vector<int> map[100][100];
int N;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

int chk(int x, int y) {
	return x == 0 || y == 0 || x == N - 1 || y == N - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T, M, K;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> K;

		vector<Node> v(K);
		for (int i = 0; i < K; i++)
		{
			cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
			map[v[i].x][v[i].y].push_back(i);
		}

		while (M--)
		{
			// 군집 삭제
			for (int i = 0; i < K; i++)
			{
				if (v[i].num == 0)
					continue;
				map[v[i].x][v[i].y].clear();
			}

			//군집 이동
			for (int i = 0; i < K; i++)
			{
				if (v[i].num == 0)
					continue;
				v[i].x += dx[v[i].dir];
				v[i].y += dy[v[i].dir];
				map[v[i].x][v[i].y].push_back(i);
			}

			for (int i = 0; i < K; i++)
			{
				if (v[i].num == 0)
					continue;

				//가장자리에 간 경우
				if (v[i].x == 0 || v[i].y == 0 || v[i].x == N - 1 || v[i].y == N - 1)
				{
					v[i].num /= 2;
					if (v[i].dir == 1) v[i].dir = 2;
					else if (v[i].dir == 2) v[i].dir = 1;
					else if (v[i].dir == 3)v[i].dir = 4;
					else v[i].dir = 3;
				}

				//여러 군집이 뭉친 경우
				else if (map[v[i].x][v[i].y].size() > 1)
				{
					int x = v[i].x;
					int y = v[i].y;
					int max_num = 0;
					int max_idx = 0;
					int sum = 0;
					int max_dir = 0;
					for (int i = 0; i < map[x][y].size(); i++)
					{
						sum += v[map[x][y][i]].num;

						if (max_num < v[map[x][y][i]].num)
						{
							max_num = v[map[x][y][i]].num;
							max_dir = v[map[x][y][i]].dir;
							max_idx = map[x][y][i];
						}
						v[map[x][y][i]].num = 0;
					}
					v[max_idx].num = sum;
					v[max_idx].dir = max_dir;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < K; i++)
		{
			res += v[i].num;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j].clear();
			}
		}
		cout << "#" << tc << " " << res << "\n";
	}
}