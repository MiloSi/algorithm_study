#pragma

#include <iostream>
#include <memory.h>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int n, m, k;
	int menu;
	int price;
	int table[21];

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> n >> m >> k;

		memset(table, 0, 21 * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			cin >> menu;
			table[menu]++;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> price;
			Answer += (table[i] * price);
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		if(Answer > k)
			cout << "N" << endl;
		else
			cout << "Y" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}