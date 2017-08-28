#include <iostream>
#include <algorithm>
using namespace std;
char input[16], output[16];
bool isVowel[26];
int l, c;
void backtraking(int st, int sz, int vowel, int consonant) {
	if (sz == l && vowel >= 1 && consonant >= 2) cout << output << endl;
	else {
		for (int i = st; i < c; i++) {
			output[sz] = input[i];
			int alphabet = input[i] - 'a';
			backtraking(i + 1, sz + 1, vowel + isVowel[alphabet], consonant + !isVowel[alphabet]);
		}
	}
}
int main() {
	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> input[i];
	sort(input, input + c);
	backtraking(0,0,0,0);
	system("pause");
	return 0;
}