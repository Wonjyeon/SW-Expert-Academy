#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int number[10];
int Data[1000001];		// �ش� idx ���ڸ� ����µ� �ɸ� ����� ����.
int len, X, T, MIN;
int INF = 987654321;

int cal(int now) {
	int num = X / now;
	int pushCnt = Data[now] + 1;
	//cout << "\nnow : " << now << endl;
	if (num == 1)
		return pushCnt;
	for (int i = X / now; i > 1; i--) {
		while (Data[i] > 0) {
			if (num%i == 0) {
				//cout << i << " ";
				pushCnt += 1 + Data[i];
				num /= i;
			}
			else
				break;
		}
		if (num == 1) {
			//cout << "\nresult : " << pushCnt << endl;
			return pushCnt;
		}
	}
	return INF;
}

void createNum(int num, int cnt) {
	if (cnt > len)		// X�� ���̺��� Ŀ���� return
		return;
	if (num > X)		// X���� ū ���ڸ� return
		return;
	if (cnt > 0)		// ������� ���� idx�� cnt ����.
		Data[num] = cnt;

	// ���� �� �ִ� ��� ���� ����
	for (int i = 0; i < 10; i++) {
		if (number[i] == 1)
			createNum(num * 10 + i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		MIN = INF;
		memset(Data, 0, sizeof(Data));
		for (int i = 0; i < 10; i++)
			cin >> number[i];
		cin >> X;

		if (X == 1 && number[1] == 1) {
			cout << "#" << tc << " " << 2 << endl;
			continue;
		}

		int tmp = X;
		len = 0;

		while (tmp > 0) {
			len++;
			tmp /= 10;
		}
		createNum(0, 0);

		for (int i = X; i > 1; i--) {
			if (Data[i] > 0 && X%i == 0) {
				MIN = min(MIN, cal(i));
			}
		}
		if (MIN == INF)
			cout << "#" << tc << " " << -1 << endl;
		else
			cout << "#" << tc << " " << MIN << endl;
	}
}