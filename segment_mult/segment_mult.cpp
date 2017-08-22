#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1000000007;
#define V vector<int>
int zeros[1000000];
int init(V& tree, const V& v, int node, int start, int end) {
	if (start == end) {
		tree[node] = v[end];
		return v[end];
	}
	return tree[node] = (init(tree, v, node * 2, start, (start + end) / 2) * init(tree, v, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}
void update(V& tree, V& zeros_tree, int node, int start, int end, int who, int od, int nw) {
	if (who > end || who < start) {
		return;
	}
	if (nw == 0) {
		zeros_tree[node] = 1;
	}
	else {
		tree[node] = ((tree[node] / od) * nw) % MOD;
		zeros_tree[node] = 0;
	}
	if (start != end) {
		update(tree, zeros_tree, node * 2, start, (start + end) / 2, who, od, nw);
		update(tree, zeros_tree, node * 2 + 1, (start + end) / 2 + 1, end, who, od, nw);
	}
}
int print(V& tree, V& zeros_tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 1;
	if (left <= start &&  end <= right) {
		if (zeros_tree[node]) return 0;
		return tree[node];
	}
	return (print(tree, zeros_tree, node * 2, start, (start + end) / 2, left, right) * 
		print(tree, zeros_tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;

}

int main() {
	int n,m,k;
	int o, x, y;
	cin >> n >> m >> k;
	V v(n);
	for (auto &i : v) {
		cin >> i;
	}
	int h = ceil(log2(n));
	V tree(1 << (h + 1));
	V zero_tree(1 << (h + 1));
	init(tree, v, 1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		cin >> o >> x >> y;
		if (o == 1) {
			int od = v[x-1];
			if (y != 0) {
				v[x - 1] = y;
			}
			if (od == y) continue;
			update(tree, zero_tree, 1, 0, n - 1, x - 1, od, y);
		}
		else if (o == 2) {

			cout << print(tree, zero_tree,  1, 0, n - 1, x - 1, y - 1) << endl; 
		}
	}


	return 0;
}