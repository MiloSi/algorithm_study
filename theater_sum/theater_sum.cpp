#pragma warning (disable:4996)
#include <cstdio>
int ans = 0;
int n, m;
int arr[41];
int dp[41][3];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", arr + i);
	}
	bool isNow;
	dp[0][0] = 1;

	for (int i = 1; i < n; i++) {
		isNow = false;
		for (int j = 0; j < m; j++) {
			if (i == arr[j]) {
				isNow = true;
				break;
			}
		}
		dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
		if (!isNow) {
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
			dp[i][2] = dp[i - 1][1];
		}
	}
	if (n == arr[m - 1]) isNow = true;
	dp[n][0] = dp[n-1][0] + dp[n -1][2];
	if (!isNow)
		dp[n][2] = dp[n - 1][1];
	printf("%d\n", dp[n][0] + dp[n][2]);
	return 0;
}
