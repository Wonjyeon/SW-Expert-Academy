#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stairs {
	int x, y, t;
	stairs(int x, int y, int t) : x(x), y(y), t(t) {};
};

struct people {
	int x, y;
	int distA, distB;
	people(int x, int y) : x(x), y(y) {};
};

vector<stairs> st;
vector<people> pe;

int T, N;
int answer;

int lunchTime(vector<int> v, int t)
{
	if (v.size() == 0)
		return 0;
	sort(v.begin(), v.end());

	int use[3] = { 0 };
	int time = v[0];

	while (true)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (!v[i])
				continue;
			if (v[i] <= time)
			{
				for (int j = 0; j < 3; j++)
				{
					if (use[j] <= 0)
					{
						use[j] = t;
						v[i] = 0;
						if (i == v.size() - 1)
							return time + t;
						break;
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			use[i]--;
		}
		time++;
	}
}

void dfs(vector<int> &A, vector<int> &B, int person)
{
	if (person >= pe.size())
	{
		answer = min(answer, max(lunchTime(A, st[0].t), lunchTime(B, st[1].t)));
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			A.push_back(pe[person].distA);
		else
			B.push_back(pe[person].distB);
		dfs(A, B, person + 1);

		if (i == 0)
			A.pop_back();
		else
			B.pop_back();
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int temp;
		pe.clear();
		st.clear();
		answer = 987654321;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				if (temp == 1)
					pe.push_back(people(j, i));
				else if (temp > 1)
					st.push_back(stairs(j, i, temp));
			}
		}
		for (int i = 0; i < pe.size(); i++)
		{
			pe[i].distA = abs(pe[i].x - st[0].x) + abs(pe[i].y - st[0].y);
			pe[i].distB = abs(pe[i].x - st[1].x) + abs(pe[i].y - st[1].y);
		}
		vector<int> stairA;
		vector<int> stairB;

		dfs(stairA, stairB, 0);
		cout << "#" << tc << " " << answer + 1 << "\n";
	}
}