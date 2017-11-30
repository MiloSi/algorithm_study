#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;
	cin >> t;
	for (int ts = 1; ts <= t; ts++) {
		cin >> n >> m;
		cout << "#" << ts << " " << m + m - n << " " << n - m << endl;
	}
}
