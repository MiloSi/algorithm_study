#pragma warning (disable:4996)
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<float, float> PF;
int main() {
	int tc, n; // testcase, number
	vector<PF> v; // points coordinate
	float ans;
	//read file and write file
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> tc; // test case 3
	// cout =  write result
	// clog = show input and output
	cout << fixed; 
	clog << fixed;  
	//two decimal place
	cout.precision(2);
	clog.precision(2);
	while (tc--) {
		//algorithm
		cin >> n;
		clog << n << endl;
		ans = 0;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			PF pf;
			cin >> pf.first >> pf.second;
			clog << pf.first << " " << pf.second << endl;
			v[i] = pf;
		}
		clog << endl;
		for (int i = 0; i < n-1; i++) {
			float _Min= 0x1fffff;
			for (int j = i + 1; j < n; j++) {
				float tmp = sqrt(pow(v[i].first - v[j].first,2) + pow(v[i].second - v[j].second,2));
				_Min = _Min < tmp ? _Min : tmp;
			}
			ans += _Min;
		}
		cout << ans << endl;
		clog << ans << endl << endl;
		v.clear();
	}
	return 0;
}