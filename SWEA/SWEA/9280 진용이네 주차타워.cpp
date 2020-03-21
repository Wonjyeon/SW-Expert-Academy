#include <iostream>
#include <queue>
using namespace std;


int N, M, X;
int space[101][2];
int car[2001];
long long money = 0;
queue<int> wait;

void init() {
	money = 0;
	while (!wait.empty()) {
		wait.pop();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			space[i][j] = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		car[i] = 0;
	}
}

void in_out(int num, int op) {
	int flag = 0;
	// ������ ��
	if (op == 1) {
		// �̹� ��ٸ��� ���� ����
		if (!wait.empty())
		{
			wait.push(num);
			return;
		}

		for (int i = 1; i <= N; i++) {
			// �� ������ �ְ�, ��ٸ��� ���� X.
			if (space[i][1] == 0) {
				space[i][1] = num;
				flag = 1;
				break;
			}
		}
		// ��ٸ��� ���� X. �� ������ X.
		if (flag == 0) {
			wait.push(num);
		}
	}

	// ������ ��
	if (op == 2) {
		int pos;
		for (int i = 1; i <= N; i++) {
			if (space[i][1] == num) {
				space[i][1] = 0;
				pos = i;
				money += space[i][0] * car[num];
				break;
			}
		}
		// ��ٸ��� ���� �־��ٸ� ���� ���� �ڸ��� �־���
		if (!wait.empty()) {
			space[pos][1] = wait.front();
			wait.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> space[i][0];
		}
		for (int i = 1; i <= M; i++) {
			cin >> car[i];
		}
		for (int i = 0; i<2 * M; i++) {
			cin >> X;
			if (X < 0) {
				in_out(-X, 2);		// ������ ��
			}
			else
				in_out(X, 1);		// ������ ��
		}
		cout << "#" << tc << " " << money << endl;
	}
}