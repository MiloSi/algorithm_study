#include <iostream>
#include <vector>
using namespace std;
int arr[20];
int main() {
	int t, n , b, ans;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		ans = 200001;
		cin >> n >> b;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector<int> v(1,0);
		for (int i = 0; i < n; i++) {
			int v_size = v.size();
			for (int j = 0; j < v_size; j++) {
				int k = v[j] + arr[i];
				if (k >= b) {
					if (ans > k) ans = k;
				}
				else
					v.push_back(k);
			}
		}
		cout << "#" << tc << " " << ans-b << endl;
		v.clear();
	}

	return 0;
}
