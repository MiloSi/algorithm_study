/*
	
	this code logic is from codeground;
*/

#include <iostream>


int coin[100];
int sequence[10001];

using namespace std;
int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	sequence[0] = 0;

	for (int i = 1; i <= k; i++)
	{
		sequence[i] = -1;
		for (int j = 0; j < n; j++)
		{
			if (coin[j] <= i) {
				if (sequence[i] == -1) sequence[i] = sequence[i - coin[j]] + 1;
				else if (sequence[i - coin[j]] + 1 < sequence[i]) sequence[i] = sequence[i - coin[j]] + 1;
			}

		}
	}
	printf("%d\n", sequence[k]);


}