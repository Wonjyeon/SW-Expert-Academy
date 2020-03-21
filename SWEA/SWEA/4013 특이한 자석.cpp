#include <iostream>
#include <math.h>
using namespace std;


void doRotate(int index, int rotate_type);
void printResult(int test_case);

int arr[4][8] = { 0 };

int main()
{

	int T, K, rotate_type, wheel;

	// test_case 수 입력
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> K;

		for (int p = 0; p < 4; p++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> arr[p][j];
			}
		}
		while (K--)
		{
			int a[4] = { 0 };
			cin >> wheel >> rotate_type;
			int r_type = rotate_type;
			int idx = wheel - 1;
			a[idx] = r_type;
			// 왼쪽으로 검사
			while (idx > 0)
			{
				if (arr[idx][6] != arr[idx - 1][2])
				{
					a[idx - 1] = r_type*-1;
					r_type *= -1;
					idx--;
				}
				else
					break;

			}
			idx = wheel - 1;
			r_type = rotate_type;
			// 오른쪽으로 검사
			while (idx < 3)
			{
				if (arr[idx][2] != arr[idx + 1][6])
				{
					a[idx + 1] = r_type*-1;
					r_type *= -1;
					idx++;
				}
				else
					break;
			}
			for (int d = 0; d < 4; d++)
			{
				if (a[d] != 0)
				{
					doRotate(d, a[d]);
				}
			}
		}

		printResult(i);
	}
}
void doRotate(int index, int rotate_type)
{
	int temp = 0;
	int arr2[8] = { 0 };
	if (rotate_type == 1)
	{
		arr2[0] = arr[index][7];
		for (int i = 1; i < 8; i++)
		{
			arr2[i] = arr[index][i - 1];
		}
		for (int i = 0; i < 8; i++)
		{
			arr[index][i] = arr2[i];
		}
	}
	else if (rotate_type == -1)
	{
		arr2[7] = arr[index][0];
		for (int i = 0; i < 7; i++)
		{
			arr2[i] = arr[index][i + 1];
		}
		for (int i = 0; i < 8; i++)
		{
			arr[index][i] = arr2[i];
		}
	}
}

void printResult(int test_case)
{
	int ans = 0;
	for (int j = 0; j < 4; j++)
	{
		if (arr[j][0] == 0)
			ans += 0;
		else if (arr[j][0] == 1)
			ans += pow(2, j);
	}
	cout << "#" << test_case << " " << ans << endl;
}