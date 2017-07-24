#include <iostream>
using namespace std;

int main() {
	int n, b, c, w;
	int result = 0;
	int *candidate;

	cin >> n;

	candidate = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> candidate[i];
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++)
	{
		candidate[i] -= b;
		w = 1;
		if (candidate[i] <= 0)
			w = 1;
		else if (candidate[i] % c == 0)
			w += candidate[i] / c;
		else
			w += (candidate[i] / c) + 1;

		result += w;
	}
	cout << result << endl;

	delete[] candidate;

	return 0;
}