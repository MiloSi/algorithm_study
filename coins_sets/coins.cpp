#pragma warning (disable:4996)
#include <cstdio>
int arr[20];
int dp[10001];
int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		
		scanf("%d", &m);

		dp[0] = 1;
		for (int i = 1; i <= m; i++)
			dp[i] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i] <= j)
					dp[j] += dp[j - arr[i]];
			}
		}
		printf("%d\n", dp[m]);
	}

	return 0;
}