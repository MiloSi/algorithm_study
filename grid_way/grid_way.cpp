#pragma warning(disable : 4996)
#include <cstdio>
int dp[16][16];
int n, m, o;
int main() {
	int y, x;
	bool checked = true;
	scanf("%d%d%d", &n, &m, &o);
	if (o != 0) {
		o--;
		y = o / (m) + 1;
		x = o % (m) + 1;
		checked = false;
	}
	else {
		y = n;
		x = m;
	}
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i == 1) {
				dp[1][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	for (int i = y; i <= n; i++) {
		for (int j = x; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	printf("%d\n",dp[n][m]);
	scanf("%d", n);
	return 0;
}