
#include <iostream>
using namespace std;


int main() {
	int t;
	int q;
	int n;

	cin >> t;

	for (int testcase = 0; testcase < t; testcase++)
	{
		cin >> n;
		q = 1;
		for (int i = 0; q < n; i++) {
			if (q & n) cout << i << " ";
			q = q << 1;
		}

	}



	return 0;
}
