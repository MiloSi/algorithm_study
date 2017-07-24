#include <iostream>
#include <algorithm>

using namespace std;




int main() {
	int n;
	long long result= 0;

	long long loop[100000];


	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> loop[i];
	}
	sort(loop, loop + n);
	for (int i = 0; i < n; i++) {
		if (result < loop[i] * (n - i))
			result = loop[i] * (n - i);
	}

	cout << result << endl;

	return 0;
}