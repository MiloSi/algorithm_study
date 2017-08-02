#include <iostream>
#include <queue>
using namespace std;
int n;
int result = 0;
bool checked[10001];
int table[10001];
typedef struct _NODE {
	int parent;
	int w;
}Node;
Node node[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, x, w;
	cin >> n;

	queue<int> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> y >> x >> w;
		node[x].parent = y;
		node[x].w = w;
		checked[y] = true;
	}
	for (int i = n; i > 1; i--) {
		if (!checked[i]) q.push(i);
		else break;
	}
	while (q.size()) {
		int child = q.front();
		int parent = node[child].parent;
		int w = node[child].w;
		q.pop();
		if (table[parent] == 0) {
			table[parent] = table[child]+w;
			if (result < table[parent]) result = table[parent];
			if (parent != 1) {
				q.push(parent);
			}
		}
		else {
			if (result < table[parent] + table[child] + w) result = table[parent] + table[child] + w;
			if (table[parent] < table[child] + w) table[parent] = table[child] + w;
		}
	}
	cout << result << endl;
}
