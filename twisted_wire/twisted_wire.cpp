#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001];
const int MAX_NUM = 1e6;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	fill(dp, dp + n, MAX_NUM);
	for (int i = 0; i < n; i++) {
		*lower_bound(dp, dp + n, arr[i]) = arr[i];
	}
	int result = n - (lower_bound(dp, dp + n, MAX_NUM) - dp);
	printf("%d\n", result);
}
