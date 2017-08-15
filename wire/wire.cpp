#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define PII pair<int ,int>
PII	p[101];
int dest[101];
int dp[101];
bool ascending(PII a, PII b) {
	return a.first < b.first;
}
int main() {
	int n;
	int k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n, ascending);
	for (int i = 0; i < n; i++) {
		dest[i] = p[i].second;
	}
	fill(dp, dp + n, 501);
	for (int i = 0; i < n; i++) {
		*lower_bound(dp, dp + n, dest[i]) = dest[i];
	}
	cout << n - (lower_bound(dp, dp + n, 501) - dp) << endl;
	return 0;
}
