#include <iostream>
using namespace std;

int coins[10];



int main() {
	int n;
	int result = 0;
	long long k;
	cin >> n >> k;


	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	int i = n - 1;
	while (k != 0)
	{
		while (k >= coins[i]) {
			k -= coins[i];
			result++;
		}
		i--;
		if (i < 0)
			break;
	}

	cout << result << endl;
	return 0;
}

