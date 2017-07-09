#pragma warning (disable : 4996)

#include <iostream>
#include <memory.h>

using namespace std;

int Answer;

inline int MAX(int a, int b)
{
	return a > b ? a : b;
}



int main(int argc, char** argv)
{
	int T, test_case;
	int arr[101][101] = { 0, };
	int table[101][101] = { 0, };

	int n = 0;

	int x = 0;
	int k;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			
			for (int j = 1; j <= n; j++) {
				cin >> k;
				arr[i][j] = arr[i-1][j] + k;
				table[i][j] = table[i][j - 1] + arr[i][j];
			}
		}

		Answer = -100;
		for (int i = 1; i <= n; i++)
		{

			for (int j = 1; j <= n; j++) 
			{
				
				for (int k = 0; k < i; k++)
				{
					for (int l = 0; l < j; l++)
					{

						int a = table[k][j] - table[k][l];
						int b = table[i][j] - table[i][l];

						if (Answer < b - a)
							Answer = b - a;
					}
				
				}
			}
		}

	

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}