#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Node {
	int idx = -1;
	char data = ' ';
	int left = -1;
	int right = -1;
};

Node nodes[101];
int N, root;

void init() {
	for (int i = 1; i <= N; i++) {
		nodes[i].left = -1;
		nodes[i].right = -1;
	}
}

void inorder(int root) {
	if (root == -1)
		return;
	inorder(nodes[root].left);
	cout << nodes[root].data;
	inorder(nodes[root].right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		init();
		for (int i = 1; i <= N; i++) {
			cin >> nodes[i].idx >> nodes[i].data;
			if ((i * 2) + 1 <= N) {
				cin >> nodes[i].left >> nodes[i].right;
			}
			else if ((i * 2) <= N) {
				cin >> nodes[i].left;
			}
		}
		cout << "#" << tc << " ";
		inorder(1);
		cout << endl;
	}
}