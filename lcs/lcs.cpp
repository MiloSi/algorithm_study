


#include <iostream>
using namespace std;

char f[1001];
char s[1001];
int dp[1002][1002] = { 0 , };

inline int MAX(int a, int b) { return a > b ? a : b; }

int main() {

	cin >> f;
	cin >> s;
	int _Max = 0;


	for (int i = 0; i < 1001; i++) {
		if (f[i] == '\0') break;
		for (int j = 0; j < 1001; j++) {
			if (s[j] == '\0') break;

			if (f[i] == s[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
				dp[i + 1][j + 1] = MAX(dp[i][j + 1], dp[i + 1][j]);

			if (dp[i + 1][j + 1] > _Max)
				_Max = dp[i + 1][j + 1];
		}
	}

	cout << _Max << endl;
	return 0;
}
