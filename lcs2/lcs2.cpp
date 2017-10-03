#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int>  PI;
#define MP make_pair
vector<PI> v[1001];
int dp[1001][1001];
string s1, s2;

int ans;

void backtracking(int idx, PI p, string s) {	
	if (idx == 0) {
		reverse(s.begin(), s.end());
		if(s.length() >= 1)
			cout << s << endl;
		return;
	}
	for (auto i : v[idx]) {
		if (i.first < p.first && i.second < p.second) {
			backtracking(idx - 1, i, s + s2[i.second]);
			return;
		}
	}
	return;
}

int main() {
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	s1 = " " + s1;
	s2 = " " + s2;
	ans = 0;
	/*
	ACAYKP
	CAPCAK
	*/
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i] == s2[j]) {
				int val = dp[i - 1][j-1] + 1;
				if (val > ans) ans = val;
				v[val].push_back(MP(i, j));
				dp[i][j] = max(dp[i][j - 1], val);
			}
			else
				dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
		}
	}

 	
	cout << ans << endl;
	backtracking(ans, MP(1001, 1001), "");
	return 0;
}