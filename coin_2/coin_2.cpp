#pragma warning(disable : 4996)
#include <cstdio>

inline int MIN(int a, int b) { return a < b ? a : b; }


/*
D(K) = 최소 코인의 수.
C(i) = 코인 i 의 크기
S(0, N, F()) = F()를 0 부터 N 까지 반복

D(K) = MIN(D(K), S(0, N, D(K - C(i)))

*/


int main() {

	int n, k;
	int coins[10];
	int dp[10001] = {0, };

	scanf("%d %d", &n, &k);



	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
		if (coins[i] <= k)
			dp[coins[i]] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] >= 0) {
				if (dp[i] == 0 && dp[i - coins[j]] != 0) {
					dp[i] = dp[i - coins[j]] + 1;
					continue;
				}
				if (dp[i - coins[j]] != 0) {
					dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
				}
			} 
		}
	}
	if(dp[k] == 0) 
		printf("-1\n");
	else 
	printf("%d\n", dp[k]);


	return 0;
}