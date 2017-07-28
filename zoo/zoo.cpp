#include <iostream>
using namespace std;
#define MOD 9901;

int zoo[100001][2];


int main() {
	int n;
	cin >> n;
	int result;
	zoo[1][0] = 2;
	zoo[1][1] = 1;



	for (int i = 2; i <= n; i++) {
		zoo[i][0] = (zoo[i - 1][0] + zoo[i - 1][1]*2) %MOD;
		zoo[i][1] = (zoo[i - 1][0] + zoo[i - 1][1]) % MOD;

	}
	result = (zoo[n][0] + zoo[n][1]) % MOD;

	cout << result << endl;

	return 0;
}