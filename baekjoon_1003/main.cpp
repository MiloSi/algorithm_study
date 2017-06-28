//#pragma warning (disable : 4996)

#include <iostream>
int main(int argc, char** argv)
{
	int t = 0;
	int n = 0;
	int zero[41] = {1, 0,};
	int ones[41] = {0, 1,};
	
	
	for(int i = 2; i <= 40; i++)
	{
		zero[i] = zero[i-1] + zero[i-2];
		ones[i] = ones[i-1] + ones[i-2];
	}
	cin >> t;
	for(int i = 0; i < t; i++ )
	{
		cin >> n;
		cout << zero[n] << " " << ones[n] << endl;
	}
	
	return 0;
}
