#include <iostream>
#include <algorithm>
using namespace std;

int table[1000];
int main() {
	int n;
	int sum = 0;
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> table[i];

	sort(table, table + n);

	for (int i = 0; i < n; i++)
	{
		sum += table[i];
		total += sum;
	}


	cout << total << endl;

	return 0;
}
