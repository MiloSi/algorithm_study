#pragma warning (disable:4996)
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
vector<int> tree, lazy;
int n, m, o, s, t;
void propagation(int node, int st, int ed) {
	if (lazy[node] != 0) {
		if (st != ed) {
			lazy[node * 2] ^= 1;
			lazy[node * 2 + 1] ^=1;
			int temp = 0;
			int m = (st + ed) / 2;
			if (lazy[node * 2]) temp += ((m - st) + 1) - tree[node*2];
			else temp += tree[node * 2];
			if (lazy[node * 2 + 1]) temp += (ed - m) - tree[node * 2+1];
			else temp += tree[node * 2 + 1];
			tree[node] = temp;
		}
		else tree[node] ^= 1;
		lazy[node] = 0;
	}
}
void update(int node, int st, int ed, int l, int r) {
	propagation(node, st, ed);
	if (r < st || ed < l) return;
	if (l <= st && ed <= r) {
		lazy[node] ^= 1;
		propagation(node, st, ed);
		return;
	}
	int m = (st + ed) / 2;
	update(node * 2, st, m, l, r);
	update(node * 2 + 1, m + 1, ed, l, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int print(int node, int st, int ed, int l, int r) {
	propagation(node, st, ed);
	if (r < st || ed < l) return 0;
	if (l <= st && ed <= r) {
		return tree[node];
	}
	int m = (st + ed) / 2;
	return print(node * 2, st, m, l, r) + print(node * 2 + 1, m + 1, ed, l, r);
}
int main() {
	int h;
	scanf("%d%d", &n, &m);
	h = ceil(log2(n));
	tree.resize(1 << (h + 1));
	lazy.resize(1 << (h + 1));
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &o, &s, &t);
		if (o == 0) {
			update(1, 1, n, s, t);
		}
		else {
			printf("%d\n", print(1, 1, n, s, t));	
		}
	}
	scanf("%d", &n);
	return 0;
}