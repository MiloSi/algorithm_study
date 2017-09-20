#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int idx = 0;
	int prev = 0;
	int n = 1;
	while ((idx = s.find(' ', prev)) != string::npos) {
		if (idx - prev != 0) {
			n++;
		}
		prev = idx + 1;
	}
	if (s[s.length() - 1] == ' ') n--;
 
	cout << n << endl;
	return 0;
}