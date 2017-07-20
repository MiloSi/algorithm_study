#include <iostream>
using namespace std;

inline int MAX(int a, int b) { return a > b ? a : b; }


int main() {

	long x;
	long table[100001] = {0,};
	int n;
	int max = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		table[i] = MAX(x, x + table[i - 1]);
		if (table[i] > max)
			max = table[i];
	}


	cout << max << endl;



}