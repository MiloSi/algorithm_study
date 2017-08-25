#include <iostream>
using namespace std;
int main() {
	int l, p, v;
	int a, b;
	for (int i = 1; ; i++) {
		cin >> l >> p >> v;
		if (l == 0) break;
		a = (v / p) * l;
		b = (v % p);
		if (b > l)  b = l;
		cout << "Case " << i << ": " << a + b << endl;
	}
	return 0;
}
