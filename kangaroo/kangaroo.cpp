#pragma warning (disable : 4996)
#include <cstdio>

inline int MAX(int a, int b) { return a > b ? a : b; }


int main() {
	int a, b, c;
	int result;
	scanf("%d %d %d", &a, &b, &c);
	result = MAX(b - a, c - b);
	printf("%d", result - 1);




	return 0;
}