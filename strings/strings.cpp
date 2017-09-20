#include <iostream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();
	int ans = 51;
	for (int i = 0; i <= len2 - len1; i++) {
		string s = b.substr(i, len1 + i);
		int k = 0;
		for (int j = 0; j < len1; j++) {
			if (s[j] != a[j]) k++;
		}
		if (ans > k)ans = k;
	}
	cout << ans;


	return 0;
}