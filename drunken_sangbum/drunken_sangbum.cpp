#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int result = sqrt(n);
		cout << result << endl;
	}
	return 0;
}