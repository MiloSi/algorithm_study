
#include <iostream>

using namespace std;

long long Answer;

long table[200001];

int main(int argc, char** argv)
{
	int T, test_case;
	int n, k;
	int x, y;
	
	char c[300000];

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n >> k;

		table[0] = 1;
		for (int i = 1; i < n; i++)
			table[i] = table[i-1] + i + 1;
		for (int j = n-1, i = n; i < n * 2 - 1; i++, j--)
			table[i] = table[i - 1] + j ;

		int k = 0;
		x = 0;
		y = 0;

		Answer = 1;

		cin >> c;
		while (c[k] != '\0') {
			switch (c[k])
			{
			case 'D': y++;
				break;
			case 'U': y--;
				break;
			case 'R': x++;
				break;
			case 'L': x--;
				break;
			}
			if (x + y < n)
			{
				if ((x + y) % 2) {
					Answer += table[x + y] - x;
				}
				else {
					Answer += table[x + y] - y;
				}
			}
			else {
				if ((x + y) % 2)
					Answer += table[x + y] - n + y + 1;
				else
					Answer += table[x + y] - n + x + 1;
			}
			k++;
		}

	
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}