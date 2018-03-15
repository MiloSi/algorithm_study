#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const long long MOD = 1000000007;
long long table[10001][16];
//Using bitmask
// a = 0, b = 1, c = 2, d = 3;
long long solution(string& str) {
	int len = str.length() -1;
	memset(table, 0, sizeof(table));

	int shift = str[0] - 'A';
	int admin = 1 << shift;
	for (int j = 1; j <= 15; j++) {
		if (j & admin &&  j & 1) {
			table[0][j] = 1;
		}
	}
	for (int i = 1; i <= len; i++) {
		int shift = str[i] - 'A';
		int admin = 1 << shift;
		for (int j = 1; j <= 15; j++) {
			if (j & admin) {
				for (int k = 1; k <= 15; k++) {
					if (k & j) {
						table[i][j] = (table[i][j] + table[i - 1][k]) % MOD;
					}
				}
			}
		}
	}
	long long retval = 0;
	for (int i = 1; i <= 15; i++) {
		retval = (retval + table[len][i]) % MOD;
	}
	return retval;
}
int main() {
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		string str;
		cin >> str;
		cout << "#" << t << " " << solution(str) << endl;
	}

}
