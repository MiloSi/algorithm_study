#pragma warning (disable:4996)
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define VL vector<long long int>
#define LI long long int
LI update(VL& tree, int node, int st, int ed, int idx, LI val) { // tree, node, start, end, index, value
	if (idx < st || ed < idx) return tree[node];
	if (st == ed) return tree[node] += val;
	int md = (st + ed) / 2;
	return tree[node] = update(tree, node * 2, st, md, idx, val)
		+ update(tree, node * 2 + 1, md + 1, ed, idx, val);
}
LI print(VL& tree, int node, int st, int ed, int left, LI right) {
	if (right < st || ed < left) return 0;
	if (left <= st && ed <= right) return tree[node];
	int md = (st + ed) / 2;
	return print(tree, node * 2, st, md, left, right)
		+ print(tree, node * 2 + 1, md + 1, ed, left, right);
}

int main() {
	int n, m, o, x, y; // n, m, order, variable1, variable2;
	scanf("%d%d", &n, &m);
	int h = ceil(log2(n));
	VL tree(1 << (h + 1));
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			update(tree, 1, 1, n, x, y);
		}
		else if (o == 2) {
			printf("%lld\n",print(tree, 1, 1, n, x, y));
		}
	}
	return 0;
}
