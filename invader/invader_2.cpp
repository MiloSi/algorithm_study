#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[4][20000];
int arr[2][20000];
int n, w;
const int INF = 0x1fffffff;
inline int _MIN(int a, int b, int c, int d) {
	a = a < b ? a : b;
	b = c < d ? c : d;
	return a < b ? a : b;
}
inline int _MIN(int a, int b) {
	return a < b ? a : b;
}
inline int _MORE(int a, int b) {
	if (a + b <= w) return 1;
	else return 2;
}
inline int _MORE(int a, int b, int c, int d) {
	if (a + b <= w && c + d <= w) return 0;
	else return 2;
}
inline int _LAST(int a, int b) {
	if (a + b <= w) return -1;
	else return 0;
}
void reset() {
	for (int i = 0; i < 4; i++) {
		fill_n(dp[i], n, 0);
	}
}
int get_dp(int cs) {
	int from, to;
	cs == 3 ? (from = 0, to = n) : (from = 1, to = n - 1);
	if (cs == 0) {
		int r1, r2;
		int c1, c2;
		r1 = _MORE(arr[0][0], arr[0][n - 1]) == 1 ? 1 : 0;
		r2 = _MORE(arr[1][0], arr[1][n - 1]) == 1 ? 1 : 0;
		c1 = _MORE(arr[0][0], arr[1][0]) == 1 ? 1 : 0;
		c2 = _MORE(arr[0][n-1], arr[1][n-1]) == 1 ? 1 : 0;

		dp[0][0] = c2 == 1 ? 3 : 4;
		dp[1][0] = r1 == 1 ? 3 : 4;
		dp[2][0] = r2 == 1 ? 3 : 4;
		if ((r1 && r2) || (c1 && c2)) dp[3][0] = 2;
		else if (r1 || r2 || c1 || c2) dp[3][0] = 3;
		else dp[3][0] = 4;
		dp[2][1] = dp[1][1] = dp[0][1] = _MIN(dp[0][0], dp[1][0], dp[2][from - 1], dp[3][from - 1]) + 2;
		dp[3][1] = dp[3][0] + _MORE(arr[0][1], arr[1][1]);
	}
	else if (cs == 1 || cs == 2) { //¼öÁ¤
		dp[0][0] =  dp[3][0] = 4;
		if(cs == 1)
			dp[1][0] = _MORE(arr[0][0], arr[0][n - 1]) + 2;
		else dp[1][0] = 4;
		if(cs == 2)
			dp[2][0] = _MORE(arr[1][0], arr[1][n - 1]) + 2;
		else dp[2][0] = 4;

		dp[0][1] = _MIN(dp[0][0], dp[1][0], dp[2][0], dp[3][0]) + 2;
		dp[1][1] = dp[2][0] + _MORE(arr[0][0], arr[0][1]);
		dp[2][1] = dp[1][0] + _MORE(arr[1][0], arr[1][1]);
		dp[3][1] = _MIN(dp[0][0], dp[1][0], dp[2][0], dp[3][0]) + _MORE(arr[0][1], arr[1][1]);
	}
	else if (cs == 3) {
		dp[0][0] = dp[1][0] = dp[2][0] = 2;
		dp[3][0] = _MORE(arr[0][0], arr[1][0]);
	 }
	for (from = from + 1; from < to; from++) {
		dp[0][from] = _MIN(dp[0][from - 1], dp[1][from - 1], dp[2][from - 1], dp[3][from - 1]) + 2;
		dp[1][from] = _MIN(dp[2][from - 1], dp[0][from - 1]) + _MORE(arr[0][from], arr[0][from-1]);
		dp[2][from] = _MIN(dp[1][from - 1], dp[0][from - 1]) + _MORE(arr[1][from], arr[1][from-1]);
		dp[3][from] = _MIN(dp[0][from - 1] + _MORE(arr[0][from-1], arr[0][from], arr[1][from-1], arr[1][from]),
			_MIN(dp[0][from - 1], dp[1][from - 1], dp[2][from - 1], dp[3][from - 1]) + _MORE(arr[0][from], arr[1][from]));
	}
	if(cs == 2)
		dp[1][from - 1] = _MIN(dp[2][from - 1], dp[0][from - 1]) + _LAST(arr[0][from], arr[0][from - 1]);
	if(cs == 1) 
		dp[2][from - 1] = _MIN(dp[1][from - 1], dp[0][from - 1]) + _LAST(arr[1][from], arr[1][from - 1]);


	return _MIN(dp[0][from - 1], dp[1][from - 1], dp[2][from - 1], dp[3][from - 1]);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &w);

		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++)
				scanf("%d", &arr[j][i]);

		if (n == 1) {
			printf("%d\n", _MORE(arr[1][0],arr[0][0]));
		}
		else {
			int result = 40020;
			for (int i = 0; i < 4; i++) {
				reset();
				int temp = get_dp(i);
				if (result > temp) result = temp;
			}
			printf("%d\n", result);
		}
	}
	return 0;
}