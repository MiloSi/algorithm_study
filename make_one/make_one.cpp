
#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
inline int min(int a, int b) {
	return a < b?  a : b;
};

int calculate(int n)
{
	if (n <= 1) return 0;
	int a = calculate(n / 2) + 1 + (n % 2);
	int b = calculate(n / 3) + 1 + (n % 3);

	return min(a, b);
}



int main() {
	int n;
	cin >> n;
	cout << calculate(n) << endl;
	return 0;
}


