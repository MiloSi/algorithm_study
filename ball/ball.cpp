#pragma warning (disable:4996)
#include <cstdio>

int main() {
	int idx = 1;
	int n, y ,x;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &y, &x);
		if (y == idx)
			idx = x;
		else if (x == idx)
			idx = y;
	}
	if (idx < 1 || idx > 3) printf("-1\n");
	else
		printf("%d\n", idx);
	return 0;

	
}