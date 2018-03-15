#include <iostream>
using namespace std;

long long solution(const int& n, const int& a, const int& b) {
	long long retval = 0x6ffffffff;

	for (int r = 1; r <= n; r++) {
		int k = n / r;
		for (int c = r; c <= k; c++) {
			long long fParam = c - r;
			long long sParam = n - c * r;
			long long tmp = a * fParam + b * sParam;

			if (retval > tmp) {
				retval = tmp;
				if (retval == 0) {
					return retval;
				}
			}
		}
	}
	return retval;
}
int main() {
	int testcase;
	int n, a, b;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> a >> b;
		cout << "#" << t << " " << solution(n, a, b) << endl;
	}

}
