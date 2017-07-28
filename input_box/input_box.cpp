#include <iostream>
using namespace std;



int box[1001];
int dp[1001];

int main() {
	int n;
	int _Max = 0;

	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> box[i];
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (box[i] > box[j]) {
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}

		if (_Max < dp[i])
			_Max = dp[i];
	}

	cout << _Max << endl;

	return 0;
}