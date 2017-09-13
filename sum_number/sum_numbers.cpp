#pragma warning (disable : 4996)
#include <cstdio>
long long int arr[10001];
int main() {
	long long int n, m;
	long long int sum = 0;
	int ans = 0;
	int i = 0, j = 0;
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i < n; i++)		scanf("%lld", &arr[i]);

	while (1) {
		if (sum >= m) sum -= arr[j++];
		else if (i == n) break;
		else sum += arr[i++];
		if (sum == m) ans++;
	}

	
	printf("%d\n", ans);


	return 0;
}