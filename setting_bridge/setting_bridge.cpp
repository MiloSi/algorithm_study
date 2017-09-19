#pragma warning (disable:4996)
#include <cstdio>
long long int dp[31][31];

long long int getResult(int m, int n) {
	if (m == n) return 1;
	if (n == 0) return 1;
	if (dp[m][n]) return dp[m][n];
	return dp[m][n] = getResult(m - 1, n - 1) + getResult(m - 1, n);
	
}
int main() {
	int t, n,m;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%lld\n", getResult(m, n));
	}
	return 0;
}

