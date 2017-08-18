#pragma warning(disable : 4996)
#include <cstdio>
const int MOD = 15746;
int n;
int main() {
	int a= 2, b =1, c;
	scanf("%d", &n);
	if (n == 1) printf("%d\n", b);
	else if (n == 2) printf("%d\n", a);
	else {
		for (int i = 3; i <= n; i++) {
			c = (a + b) % MOD;
			b = a;
			a = c;
		}
		printf("%d\n", c);
	}

	return 0;
}