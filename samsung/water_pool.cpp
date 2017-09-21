#include <iostream>
using namespace std;
int ans;
int pay[4];
int month[13];
int dp[13];
inline int _Min(int a, int b) {
	return a < b ? a : b;
}
int main() {

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		ans = 0;
		for (int i = 0; i < 4; i++)
			cin >> pay[i];
		for (int i = 1; i <= 12; i++)
			cin >> month[i];
		
		for (int j = 1; j <= 12; j++) {
			dp[j] = _Min(pay[0] * month[j], pay[1]);
			dp[j] += dp[j - 1];
			if (j >= 3) {
				dp[j] = _Min(dp[j], dp[j-3] + pay[2]);
			}	
		}
		ans = _Min(dp[12], pay[3]);
		cout << "#" << test << " " << ans << endl;
	}
	return 0;
}
