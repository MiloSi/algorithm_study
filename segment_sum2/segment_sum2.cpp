#pragma warning (disable:4996)
#include <cstdio>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;
int n, m, k;
vector<LL> tree;
vector<LL> lazy;
vector<LL> leaves;
LL init(int node, int st, int ed) {
	if (st > ed) {
		return 0;
	}
	if (st == ed) {
		return tree[node] = leaves[st];
	}
	int m = (st + ed) / 2;
	return tree[node] = init(node * 2, st, m) + init(node * 2 + 1, m + 1, ed);
}
void propagation(int node, int st, int ed) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (ed - st + 1);
		if (st != ed) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int st, int ed, int l, int r, LL val) {
	propagation(node, st, ed);
	if (r < st || ed < l) return;
	if (l <= st && ed <= r) {
		tree[node] += (ed - st + 1) * val;
		if (ed != st) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int m = (st + ed) / 2;
	update(node * 2, st, m, l, r, val);
	update(node * 2 + 1, m + 1, ed, l, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
LL print(int node, int st, int ed, int l, int r) {
	propagation(node, st, ed);

	if (ed < l || r < st) return 0;
	if (l <= st && ed <= r) return tree[node];
	int m = (st + ed) / 2;
	return print(node * 2, st, m, l, r) +
		print(node * 2 + 1, m + 1, ed, l, r);
}
int main() {
	int h, order, l, r;
	LL v;
	scanf("%d%d%d", &n, &m, &k);
	leaves.resize(n + 1);
	h = ceil(log2(n));
	tree.resize(1 << (h + 1));
	lazy.resize(1 << (h + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &leaves[i]);
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		scanf("%d", &order);
		if (order == 1) {
			scanf("%d%d%lld", &l, &r, &v);
			update(1, 1, n, l, r, v);
		}
		else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", print(1, 1, n, l, r));
		}
	}
	return 0;
}