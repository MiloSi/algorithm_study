#include <iostream>
#include <vector>
// 1,000,000,000 < INT_MAX
using namespace std;
#define LOP(i, j) for(int i = 0; i < j; i++)
int arr[500][500];
int dp[500][500];
int n, m;
int yf[4] = { -1,1,0,0 };
int xf[4] = { 0,0,-1,1 };
int dfs(int y, int x) {
	int y1, x1, w = 0;
	LOP(i, 4) {
		y1 = y + yf[i];	
		x1 = x + xf[i];
		if (y1 < 0 || y1 > n - 1 || x1 < 0 || x1 > m - 1) continue;
		if (arr[y1][x1] > arr[y][x]) {
			if (dp[y1][x1] == -1) {
				dp[y1][x1] = 0;
				w += dfs(y1, x1);
			}
			else {
				w += dp[y1][x1];
			}
		}
	}
	dp[y][x] = w;
	return dp[y][x];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	LOP(i, n) LOP(j, m) cin >> arr[i][j];
	LOP(i, n) LOP(j, m) dp[i][j] = -1;
	dp[0][0] = 1;
	dp[n - 1][m - 1] = 0;
	cout << dfs(n - 1, m - 1) << endl;
	return 0;
}