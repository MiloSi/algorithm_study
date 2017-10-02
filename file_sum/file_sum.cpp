#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int dp[500][500];
int arr[500][500];
vector<int> tree;
int n;
inline int _MIN(int a, int b) {
	return a < b ? a : b;
}


int update(int nd, int st, int ed, int left, int right, int value) {
	if (right < st || ed < left) return tree[nd];
	if (left <= st && ed <= right) return tree[nd] = value;
	int md = (st + ed) / 2;

	return tree[nd] = update(nd * 2, st, md, left, right, value) +
		update(nd * 2 + 1, md + 1, ed, left, right, value);
}
int print(int nd, int st, int ed, int left, int right) {

	if (right < st || ed < left)return 0;
	if (left <= st && ed <= right) return tree[nd];
	int md = (st + ed) / 2;

	return print(nd * 2, st, md, left, right) + print(nd * 2 + 1, md + 1, ed, left, right);
}


int get(int left, int right) {
	int sum = print(1, 1, n, left, right);
	int temp = 0x11111111;
	for (int i = left; i < right; i++) {
		int a = dp[left][i] + dp[i + 1][right];
		temp = _MIN(temp, a);
	}
	return sum + temp;
}



int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		int h = ceil(log2(n+1));
		tree.resize(1 << (h + 1), 0);
		int x;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&x);
			update(1, 1, n, i, i, x);
		}
		for (int len = 1; len <= n-1; len++) {
			for (int i = 1; i <= n - len; i++) {
				dp[i][i + len] = get(i, i + len);
			}
		}
		printf("%d\n", dp[1][n]);
		tree.clear();
	}
	return 0;
}