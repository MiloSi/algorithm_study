#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
int n, m, k;
ll update(vector<ll>& tree, int node, int start, int end, int pos, int value) {
	if (pos > end || pos < start) return tree[node];
	if (start == end) return tree[node] = value;
	return tree[node] = (update(tree, node * 2, start, (start + end) / 2, pos, value) *
		update(tree, node * 2+1,  (start + end) / 2 + 1, end, pos, value)) % MOD;
}
ll print(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 1ll;
	if (start >= left && end <= right) return tree[node];
	return (print(tree, node*2, start, (start + end) / 2, left, right) *
		print(tree, node*2 + 1, (start + end) / 2 + 1, end, left, right)) % MOD;

}
int main() {
	int n, m, k;
	int o, x, y;
	cin >> n >> m >> k;
	int h = ceil(log2(n));
	vector<ll> tree(1 << (h+1));
	for (int i = 1; i <= n; i++)	{
		cin >> x;
		update(tree, 1, 1, n, i, x);
	}
	for (int i = 1; i <= k+ m; i++) {
		cin >> o >> x >> y;
		if (o == 1) {
			update(tree, 1, 1, n, x, y);
		}
		else if (o == 2) {
			cout << print(tree, 1, 1, n, x, y) << endl;
		}
	}
	return 0;
}
