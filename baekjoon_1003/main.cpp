/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#pragma warning (disable : 4996)

#include <iostream>
#include <memory.h>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int arr[101][101];

	int tmax = 0;
	int n = 0;
	int sum;
	int v;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n; 
		sum = 0;

		memset(arr, 0, 101 * 101 * sizeof(int));
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> v;
				arr[j][i] = v + arr[j][i-1];
			}
		}
		Answer = -500000;
		for (int x = 1; x <= n; x++)
		{

			for (int i = x; i <= n; i++)
			{
				sum = 0;
				for (int j = x; j <=  n; j++)
				{
					v = arr[j][i] - arr[j][x-1];

					sum = v + sum > sum ? v + sum : sum;
					Answer = sum > Answer ? sum : Answer;
				}
			}
		}



	
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}