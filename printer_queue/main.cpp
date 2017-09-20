#pragma warning (disable:4996)
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int orders[100];
bool myRule(int a, int b) {
	return a > b;
}


typedef struct _Node {
	int o;
	int w;

}Node;
int main() {
	int t;
	int n, m;
	scanf("%d", &t);
	while (t--) {
		queue<Node> q;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", orders + i);
			Node nd = { i, orders[i] };
			q.push(nd);
		}
		sort(orders, orders + n, myRule);
		int idx = 0;
		while (1) {
			Node nd = q.front();
			q.pop();
			if (nd.w != orders[idx]) {
				q.push(nd);
			}
			else {
				if (nd.o == m) {
					break;
				}
				idx++;
			}
		}
		printf("%d\n", idx + 1);
	}
	
	return 0;
}