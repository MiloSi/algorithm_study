#pragma warning (disable:4996)
#include <cstdio>
using namespace std;
char board[51][51];
char colors[2] = { 'W','B' };

inline int _MIN(int a, int b) {
	return a < b ? a : b;
}
int getNumberOfDraw(int y, int x) {
	int color = 0;
	int r1 = 0, r2 = 0;
	for (int i = y; i < y + 8; i++) {
		color = i % 2;
		for (int j = x; j < x + 8; j++) {
			if (colors[color] == board[i][j])
				r1++;
			else
				r2++;

			color = (color + 1) % 2;
		}
	}

	return _MIN(r1,r2);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	int ans = 2500;
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			ans = _MIN(ans , getNumberOfDraw(i, j));
		}
	}
	printf("%d\n", ans);

	return 0;
}