#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
struct value {
	int d, x, y;
};
value extended_euclid(int a, int b) {
	value ans;
	if (b == 0) return { a, 1, 0 };
	value v = extended_euclid( b, a%b );
	ans = { v.d, v.y, v.x - (a / b)*v.y };
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, t; // a and b are less than 1,000,000,001. It means less than integer Max 
	cin >> t; // testcase
	cerr << "Testcase : " <<  t << endl;
	for (int tc = 1; tc <= t; tc++) {
		cerr << "Problem " << tc << endl << endl;
		cin >> a >> b;
		cerr << a << " " << b << endl << endl;
		value ans = extended_euclid(a, b);

		cerr << "Answer " << tc << endl << endl;
		cerr << ans.x << " " << ans.y << " " << ans.d << endl << endl;
		cout << ans.x << " " << ans.y << " " << ans.d << endl;
	}
	return 0;
}


