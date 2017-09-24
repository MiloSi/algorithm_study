#pragma warning (disable:4996)
#include <cstdio>
int n,t;
typedef struct _NODE {
	int k;
	int s;
}Node;
Node nd[101];
int dp[101][10000];
int _max(int a, int b) {
	return a > b ? a : b;
}
int ans = 0;

int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &nd[i].k, &nd[i].s);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < t; j++) {
			if (nd[i].k > j) dp[i][j] = dp[i - 1][j];
			else if (dp[i - 1][j] < dp[i - 1][j - nd[i].k] + nd[i].s) dp[i][j] = dp[i - 1][j - nd[i].k] + nd[i].s;
			else dp[i][j] = dp[i - 1][j];
		}
	}
	for (int i = 0; i < t; i++) {
		ans = _max(dp[n][i], ans);
	}

	printf("%d\n", ans);
	return 0;
}