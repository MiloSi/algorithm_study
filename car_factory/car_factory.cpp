#pragma warning (disable :4996)
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define LLI long long int
vector<LLI> tree, lazy, leaves;
vector<int> st, ed;
vector<vector<int>> sub;
int n, m, a, x;
int c;
char o;
void propagate(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void dfs(int idx) {
	st[idx] = ++c;
	for (auto i : sub[idx]) {
		dfs(i);
	}
	ed[idx] = c;
}
void update(int node, int start, int end, int l, int r, int value) {
	propagate(node, start, end);
	if (r < start || end < l) return;
	if (l <= start && end <= r) {
		lazy[node] = value;
		propagate(node, start, end);
		return;
	}
	int m = (start + end) / 2;
	update(node * 2, start, m, l, r, value);
	update(node * 2 + 1, m + 1, end, l, r, value);
}
LLI show(int node, int start, int end, int idx) {
	propagate(node, start, end);
	if (idx < start || end < idx) return 0;
	if (start == end) return tree[node];
	int m = (start + end) / 2;
	return show(node * 2, start, m, idx) + show(node * 2 + 1, m + 1, end, idx);
}

int main() {
	int h;
	scanf("%d%d%d", &n, &m, &x);
	//memory allocation
	sub.resize(n + 1);
	st.resize(n + 1);
	ed.resize(n + 1);
	leaves.resize(n + 1);
	h = ceil(log2(n));
	tree.resize(1 << (h + 1));
	lazy.resize(1 << (h + 1));
	leaves[1] = x;
	for (int i = 2; i <= n; i++) {
		scanf("%d%d", &leaves[i], &a);
		sub[a].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, st[i], st[i], leaves[i]);
	}
	for (int i = 0; i <= m; i++) {
		scanf(" %c", &o);
		if (o == 'p') {
			scanf("%d%d", &a, &x);
			update(1, 1, n, st[a] + 1, ed[a], x);
		}
		else if (o == 'u') {
			scanf("%d", &a);
			printf("%lld\n", show(1, 1, n, st[a]));
		}
	}
	return 0;
}