#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int L, U, X, need;
		cin >> L >> U >> X;
		if (X<L)
			need = L - X;
		else if (X >= L && X <= U)
			need = 0;
		else if (X>U)
			need = -1;
		cout << "#" << test_case << " " << need << endl;
	}
	return 0;
}