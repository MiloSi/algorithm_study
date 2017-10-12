#pragma warning (disable:4996)
#include <iostream>
using namespace std;
int t, n, m, c, ans;
int arr[10][10];
int mults[10][10];
int dp[10][10];

int getValue(int y, int x) {
	int total = 0;
	int box[33] = { 0, };
	int totals[33] = { 0, };
	int idx = 1;

	for (int i = 0; i < m; i++) {
		for (int j = idx; j < idx*2; j++) {
			box[j] = box[j-idx] + arr[y][x + i];
			totals[j] = totals[j-idx] + mults[y][x + i];
			if (totals[j] > total && box[j] <= c) total = totals[j];
		}
		idx = idx << 1;
	}
	return  total;
}
int getMax(int y, int x) {
	int a = dp[y][x];
	int b = 0;
	for (int j = x + m; j < n; j++)
		b = b > dp[y][j] ? b : dp[y][j];

	for (int i = y + 1; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			b = b > dp[i][j] ? b : dp[i][j];
		}
	}
	return a + b;
}


int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 0;
		cin >> n >> m >> c;	

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			mults[i][j] = arr[i][j] * arr[i][j];
			dp[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n- m; j++) {
				dp[i][j] = getValue(i, j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - m; j++) {
				int tmp = getMax(i, j);
				ans = ans > tmp ? ans : tmp;
			}
		}



		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
