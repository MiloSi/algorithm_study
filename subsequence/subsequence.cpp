#pragma warning(disable: 4996)
#include <iostream>
#include <string>
using namespace std;
int n;
int dp[100][10000];
string X, Z;
int x_len; // size <= 10000
int z_len; // size <= 100
/*
situation
	Your job is to write a program that counts the number of
	occurrences of Z in X as a subsequence such that each has a
	distinct index sequence
*/

int main() {
	// recently, I learned 'file read', 'file write' using freopen
	freopen("input.txt", "r", stdin);  //read input file 
	freopen("output.txt", "w", stdout); // write output file
	cin >> n;
	for(int tc = 0; tc < n; tc++) { //tc means testcase
		cin >> X >> Z;
		x_len = X.length();
		z_len = Z.length();

		int sum;

		/* algorithm part 
		 complexity will be (z_len * x_len)
		 */

		//init dp table
		for (int j = 0; j < z_len; j++)
			for (int i = 0; i < x_len; i++)
				dp[j][i] = 0;
		//set first dp line
		for (int i = 0; i < x_len; i++) {
			if (X[i] == Z[0]) dp[0][i] = 1;
		}
		//set all dp tables
		for (int j = 1; j < z_len; j++) {
			sum = 0;
			for (int i = j; i < x_len; i++) {
				sum += dp[j - 1][i - 1];
				if (X[i] == Z[j])
					dp[j][i] = sum;
			}
		}
		int ans = 0;
		//get sum of values
		for (int i = 0; i < x_len; i++) {
			ans += dp[z_len - 1][i];
		}
	
		cout << ans << endl; // write output file
		cerr << ans << endl; // show console screen
	}

	return 0;
}