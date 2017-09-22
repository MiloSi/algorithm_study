#include <iostream>
#include <string>
using namespace std;

string chro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {
	string s;
	cin >> s;
	int idx = 0;
	int len = s.length();
	bool isChro = false;
	int ans = 0;

	while (idx < len) {
		isChro = false;
		for (int i = 0; i < 8; i++) {
			int sublen = chro[i].length();
			if (idx + sublen > len) continue;

			string str = s.substr(idx, sublen);
			
			if (str.compare(chro[i]) == 0) {
				idx += sublen;
				isChro = true;
				break;
			}
		}
		if (!isChro) {
			idx++;
		}
		ans++;
	}
	cout << ans << endl;

	return 0;

}