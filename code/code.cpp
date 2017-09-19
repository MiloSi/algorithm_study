#pragma warning (disable : 4996)
#include <iostream>
#include <string>
using namespace std;
int dp[5001];
const int MOD = 1000000;
int main() {
	string str;
	cin >> str;
	int len = str.length();
	int prev, num;
	int idx;
	if (len >= 2) {
		idx = len - 2;
		prev = str[idx+1] - '0';
		num = str[idx] - '0';
		if (prev == 0) dp[idx + 1] = 0;
		else dp[idx + 1] = 1;

		if (num == 0)  dp[idx] = 0;

		else if (num == 2) {
			if (prev <= 6) dp[idx] = dp[idx + 1] + 1;
			else dp[idx] = 1;
		}
		else if (num < 2) {
			dp[idx] = dp[idx + 1] + 1;
		}
		else {
			dp[idx] = 1;
		}
		idx--;
		for (; idx >= 0; idx--) {
			prev = num;
			num = str[idx] -'0';
			if (num == 0) {
				dp[idx] =0;
			}
			else if (num == 2) {
				if (prev <= 6)
					dp[idx] = (dp[idx + 1] + dp[idx + 2]) % MOD;
				else
					dp[idx] = dp[idx + 1];
			}
			else if (num < 2) {
				dp[idx] = (dp[idx + 1] + dp[idx + 2]) % MOD;
			}
			else {
				dp[idx] = dp[idx + 1];
			}
		}

		cout << dp[0] << endl;
	}
	else cout << 1 << endl;
	return 0;

}
