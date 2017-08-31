#pragma warning (disable : 4996)
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> leaves, tree, lazy;
int init(int node, int st, int ed) {
	if (st == ed) {
		return tree[node] = leaves[st];
	}
	int m = (st + ed) / 2;
	return tree[node] = init(node * 2, st, m) ^ init(node * 2 + 1, m+1, ed);
}
void propagation(int node, int st, int ed) {
	if (lazy[node] != 0) {
		//수정수정
		if ((ed - st + 1) % 2)
			tree[node] ^= lazy[node];
		if (st != ed) {
			lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ lazy[node];
			lazy[node * 2] = lazy[node * 2] ^ lazy[node];
		}
		lazy[node] = 0;
		//tree[node] += lazy[node] 
	}
}
void update(int node, int st, int ed, int l, int r, int value) {
	propagation(node, st, ed);
	if (r < st || ed < l) return;
	if (l <= st && ed <= r) {
		if((ed - st + 1) % 2)
			tree[node] = tree[node] ^ value;
		if (ed != st) {
			lazy[node * 2] ^= value;
			lazy[node * 2 + 1] ^= value;
		}
		return;
	} 
	int m = (st + ed) / 2;
	update(node * 2, st, m, l, r, value);
	update(node * 2 + 1, m + 1, ed, l, r, value);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int print(int node, int st, int ed, int l, int r) {
	propagation(node, st, ed);
	if (r < st || ed < l) return 0;
	if (l <= st && ed <= r) {
		return tree[node];
	}
	int m = (st + ed) / 2;
	return print(node*2, st, m, l, r) ^ print(node*2+1, m + 1, ed, l, r);
}
int main() {
	int n, m, t, a, b, c, h;
	scanf("%d", &n);
	h = ceil(log2(n));
	leaves.resize(n + 1);
	tree.resize(1 << (h + 1));
	lazy.resize(1 << (h + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &leaves[i]);
	}
	init(1, 1, n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &a, &b, &c);
			if (a < b)
				update(1, 1, n, a + 1, b + 1, c);
			else
				update(1, 1, n, b + 1, a + 1, c);
		}
		else {
			scanf("%d%d", &a, &b);
			if (a < b)
				printf("%d\n", print(1, 1, n, a + 1, b + 1));
			else
				printf("%d\n", print(1, 1, n, b + 1, a + 1));
		}
	}
	return 0;

}