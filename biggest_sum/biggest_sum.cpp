#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {

	int n;
	int _max = 0;
	cin >> n;



	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
		if (_max < dp[i])
			_max = dp[i];
	}

	cout << _max << endl;




	return 0;
}
