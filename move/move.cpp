#include <iostream>
using namespace std;

int dp[1001][1001];
inline int MAX(int a, int b) { return a > b ? a : b; }

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> dp[i][j];
		dp[i][j] += MAX(dp[i - 1][j], dp[i][j - 1]);
	}
	cout << dp[n][m] << endl;

	return 0;
}