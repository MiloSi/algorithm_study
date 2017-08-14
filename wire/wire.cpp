#include <iostream>
using namespace std;
int arr[501];
int dp[501][501];
inline int MAX(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int n;
	int limit = 0;
	int x, y; 
	int k = 0;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 1; i <= 500; i++) {
		for (int j = i; j <= 500; j++) {
			if (arr[j] == 0 || arr[i] <= arr[j]) dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
			else if (arr[i] > arr[j]) {
				dp[i][j] = MAX(dp[i][j-1], dp[i-1][j-1] +1);
			}
		}
	}
	cout << dp[500][500] << endl;
	return 0; 
}
