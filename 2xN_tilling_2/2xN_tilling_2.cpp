#pragma warning(disable : 4996)
#include <cstdio>
#define MOD 10007





int main() {
	int n;
	int rectangles[1001] = { 0 };

	scanf("%d", &n);


	rectangles[1] = 1;
	rectangles[2] = 3;

	for (int i = 3; i <= n; i++) {
			rectangles[i] = (rectangles[i - 1] + (rectangles[i - 2] * 2)) % MOD;
	}

	printf("%d\n", rectangles[n]);

	return 0;

}