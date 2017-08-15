#include <iostream>
using namespace std;
#define LOP(i,n) for(int i = 0; i < n; i++)
inline int MAX(int a, int b) { return a > b ? a : b; }
int arr[1000];
int dp[1000];
int main() {
	int n;
	int result = 0;
	cin >> n;
	LOP(i, n) {
		cin >> arr[i];
		LOP(j, i) {
			if (arr[i] < arr[j]) {
				dp[i] = MAX(dp[j], dp[i]);
			}
		}
		dp[i]++;
		if (result < dp[i]) result = dp[i];
	}
	cout << result << endl;
	return 0;
}