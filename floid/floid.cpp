#pragma warning (disable:4996)
#include <cstdio>
int arr[101][101];
inline int _MIN(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int n, m;
	scanf("%d%d", &n,&m);
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)	{
			if(i != j)
				arr[i][j] = 0x2fffffff;
		}
	
	int a, b,x;
	for (int i = 0; i < m; i++)	{
		scanf("%d%d%d", &a, &b, &x);
		arr[a][b] = _MIN(arr[a][b], x);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				arr[j][k] = _MIN(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}