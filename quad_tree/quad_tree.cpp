#include <iostream>
#include <string>
using namespace std;
char img[100][100];



string div(int fy, int ty, int fx, int tx) {
	if (fy >= ty || fx >= tx) {
		string s; 
		s = img[fy][fx];
		return s;
	}
	string s[4];

	int midx = (tx + fx) / 2;
	int midy = (ty + fy) / 2;

	s[0] = div(fy, midy, fx, midx);
	s[1] = div(fy, midy, midx + 1, tx);
	s[2] = div(midy +1, ty, fx, midx);
	s[3] = div(midy + 1, ty, midx + 1, tx);

	
	bool check = true;
	for(int t = 3; t >=1; t--)
	{
		if (s[t].compare(s[t - 1])) {
			check = false;
			break;
		}
		if (s[t].length() != 1) {
			check = false;
			break;
		}
		
	}
	if (check) {
		return s[0];
	}
	else {
		
		string r;
		r = "(";
		for (int i = 0; i < 4; i++)
			r += s[i];
		r += ")";
		return r;
	}
}


int main() {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <=n; j++)
		cin >> img[i][j];


	string s;
	s =	div(1, n, 1, n);

	
	cout << s << endl;


	system("pause");


	return 0;
}