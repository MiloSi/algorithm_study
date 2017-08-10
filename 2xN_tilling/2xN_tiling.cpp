#include<iostream>
using namespace std;
int main() {
	int n, r;
	cin >> n;
	if (n == 1) cout << 1 << endl;
	else if (n == 2) cout << 2 << endl;
	else {

		int a = 1;
		int b = 2;
		for (int i = 3; i <= n; i++)
		{
			r = (a + b) % 10007;
			a = b % 10007;
			b = r;
		}
		cout << r << endl;
	}



	return 0;
}

