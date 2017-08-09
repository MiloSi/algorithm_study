#include <iostream>
using namespace std;
int main() {
	long long n, m;
	long long result;

	cin >> n >> m;



	// 0 : 1 2 3 4 5
	// 1 : 8 7 6 5 12
	// 2 : 16 9 10 11 20 
	// 

	if (n == 1)
		result = 8 * m;
	else if (n == 5) result = (8 * m) + 4;
	else if ((m % 2) ==0) {
		result = 8 * ((m+1) / 2) + (n - 1);
	}
	else {
		result=	8 * ((m+1)/ 2) - (n - 1);
	}
	cout << result << endl;
}