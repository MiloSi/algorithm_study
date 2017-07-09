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

	int tmax = 0;
	int n = 0;
	int k;
	int sum;
	int v;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			
			for (int j = 1; j <= n; j++) {
				cin >> k;
				arr[i][j] = arr[i-1][j] + k;
			}
		}

		Answer = 0xffffffff;
		for (int i = 1; i <= n; i++)
		{

			for (int j = 1; j <= n; j++) 
			{
				 
				for (int k = 1; k < i; k++)
				{
					int a = MAX(arr[i][j], arr[i][j] - arr[k][j]);

					if (Answer < a)
						Answer = a;


				}
			}
		}

	


		Answer = 0;

		


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}