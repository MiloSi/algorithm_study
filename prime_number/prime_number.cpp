#pragma warning (disable :4996)
#include <cstdio>
bool arr[123456 *2 +1];
int main() {
	arr[0] = arr[1] = true;
	int n;
	for (int i = 2; i <= 123456 * 2; i++) {
		if (!arr[i]) {
			for (int j = i + i; j <= 123456 * 2; j += i)
				arr[j] = true;
		}
	}
	while (1) {
		scanf("%d%", &n);
		if (n == 0) break;
		int	sum = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			if (!arr[i])
				sum++;
		}
		printf("%d\n", sum);

	}
	return 0;
}