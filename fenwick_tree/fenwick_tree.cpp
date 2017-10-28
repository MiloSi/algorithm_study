#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, d, k, j; //n은 천만
vector<int> tree;
vector<int> arr;
void update(int idx, int diff) {
	while (idx <= n) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}
int print(int idx) {
	int sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void main() {
	cin >> n >> k >> j;
	tree.resize(n+1);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	d = k + j;
	int o, a, b;
	for (int i = 0; i < d; i++) {
		cin >> o >> a >> b;
		if (o == 1) {
			int diff = b - arr[a];
			arr[a] = b;
			update(a, diff);
		}
		else if (o == 2) {
			int ans = print(b) - print(a-1);
			cout << ans << endl;
		}
	}
}
