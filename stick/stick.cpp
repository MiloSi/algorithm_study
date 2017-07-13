#include <iostream>

using namespace std;
int x;
int s = 0;

inline int calculate(int n)
{
	if (x >= n)
	{
		x -= n;
		s++;
		return 0;
	}
	return 1;
}


int main() {
	

	cin >> x;
	int i =0;
	int j = 64;

	while (x != 0) {
		i = 1;
		j = 64;
		while (i) {
			i = calculate(j);
			j = j >> 1;
		}
	}

	cout << s << endl;

	return 0;
}