#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int number[10];
int Data[1000001];		// 해당 idx 숫자를 만드는데 걸린 연산수 저장.
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
	if (cnt > len)		// X의 길이보다 커지면 return
		return;
	if (num > X)		// X보다 큰 숫자면 return
		return;
	if (cnt > 0)		// 만들어진 숫자 idx에 cnt 저장.
		Data[num] = cnt;

	// 만들 수 있는 모든 숫자 생성
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