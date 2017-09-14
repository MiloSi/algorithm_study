#pragma warning (disable:4996)
#include <cstdio>
const int MOD = 10007;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int arr[2][1001];

	for (int i = 0; i < 1001; i++)	{
		arr[0][i] = 1;
		arr[1][i] = 1;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			arr[1][j] = (arr[0][j - 1] + arr[0][j]) % MOD;
		}
		for (int j = 1; j <= i; j++)
			arr[0][j] = arr[1][j];
	}
	printf("%d\n", arr[1][m]);

	return 0;
}