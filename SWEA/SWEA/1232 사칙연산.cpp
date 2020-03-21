#include <iostream>
#include <string>
using namespace std;

#define Plus -1
#define Minus -2
#define Multi -3
#define Div -4

struct Node {
	int data = -1;
	int left = -1;
	int right = -1;
};
int N, result;
Node nodes[1001];

void init()
{
	for (int i = 1; i <= N; i++) {
		nodes[i].data = -10;
		nodes[i].left = -1;
		nodes[i].right = -1;
	}
}

int postorder(int root) {
	int leftdata;
	int rightdata;
	if (nodes[root].data == -10)
		return result;
	int curdata = nodes[root].data;
	if (curdata == Minus || curdata == Plus || curdata == Multi || curdata == Div) {
		leftdata = postorder(nodes[root].left);
		rightdata = postorder(nodes[root].right);
		if (curdata == Minus) {
			result = leftdata - rightdata;
		}
		else if (curdata == Plus)
			result = leftdata + rightdata;
		else if (curdata == Multi)
			result = leftdata * rightdata;
		else if (curdata == Div)
			result = leftdata / rightdata;
		nodes[root].data = result;
	}
	return nodes[root].data;
}

int main() {
	result = 0;
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		init();
		for (int i = 1; i <= N; i++) {
			string str; int idx;
			cin >> idx >> str;
			if (!str.compare("+") || !str.compare("-") || !str.compare("*") || !str.compare("/")) {
				cin >> nodes[i].left >> nodes[i].right;
				if (!str.compare("+"))
					nodes[i].data = Plus;
				else if (!str.compare("-"))
					nodes[i].data = Minus;
				else if (!str.compare("*"))
					nodes[i].data = Multi;
				else if (!str.compare("/"))
					nodes[i].data = Div;
			}
			else {
				nodes[i].data = stoi(str);
			}
		}
		postorder(1);
		cout << "#" << tc << " " << result << endl;

	}
}

