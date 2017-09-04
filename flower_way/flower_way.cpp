#pragma warning (disable:4996)
#include <cstdio>
int n;
int arr[10][10];
int dp[10][10];
int xf[5] = { 0,0,0,-1,1 };
int yf[5] = { 0,-1,1,0,0 };
int dy[4] = { 1,1,1,2 };
int dx[4] = { -1,0,1,0 };
int result = 3000;
void setting(int y, int x) {
	for (int i = 0; i < 5; i++) {
		dp[y][x] += arr[y + yf[i]][x + xf[i]];
	}	
}
bool checked(int y, int x, int y1, int x1) {
	for (int i = 0; i < 4; i++) {
		if ((y1 + dy[i]) == y && (x1 + dx[i]) == x) return false;
	}
	return true;
}
bool checked(int y, int x, int y1, int x1, int y2, int x2) {
	if (!checked(y, x, y1, x1)) return false;
	for (int i = 0; i < 4; i++) {
		if ((y2 + dy[i]) == y && (x2 + dx[i]) == x) return false;
	}
	return true;
}
void making_flower(int first, int second, int v) {
	if (second != -1) {
		int x1 = first % n;
		int y1 = first / n;
		int x2 = second % n;
		int y2 = second / n;
		int y = y2;
		int x = x2+3;
		if (x >= n-1) {
			x = 1;
			y++;
		}	
		while (y != n - 1) {
			if (checked(y, x, y1, x1, y2, x2)) {
				if (v + dp[y][x] < result)
					result = v + dp[y][x];
			}
			x++;
			if (x == n - 1) {
				x = 1;
				y++;
			}
		}
	}
	else {
		int x1 = first % n;
		int y1 = first / n;
		int y = y1;
		int x = x1 + 3;
		if (x >= n - 1) {
			x = 1;
			y++;
		}
		while (y != n - 1) {
			if (checked(y, x, y1, x1)) {
				making_flower(first, y	*n + x, v + dp[y][x]);
			}
			x++;
			if (x >= n - 1) {
				x = 1;
				y++;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			setting(i, j);
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			making_flower(i*n + j, -1, dp[i][j]);
		}
	}
	printf("%d\n", result);
	return 0;
}