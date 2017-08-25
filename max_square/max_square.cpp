#include <iostream>
using namespace std;
int n, m;
char board[1001][1002];
int rows[1001][1001];
int cols[1001][1001];
int dp[1001][1001];
inline int MIN(int a, int b) {
	return a < b ? a : b;
}
int main() {
	cin >> n >> m;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '1') {
				rows[i][j] = rows[i][j - 1] +1;
				cols[i][j] = cols[i - 1][j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = MIN(rows[i][j], cols[i][j]);
			if (dp[i][j] > 0 && dp[i - 1][j - 1] == 0) dp[i][j] = 1;
			else if (dp[i][j] > 0 && dp[i - 1][j - 1] > 0) dp[i][j] = MIN(dp[i - 1][j - 1] + 1, dp[i][j]);
			int temp = dp[i][j] * dp[i][j];
			if (result < temp) result = temp;
		}
	}
	cout << result << endl;
}

