#pragma warning(disable : 4996)
#include <cstdio>

int main() {
	int n;
	long long result = 1;
	long long zero = 1;
	long long ones = 1;

	//long long zero[91] = { 0, };
	//long long ones[91] = { 0, };



	scanf("%d", &n);


	for (int i = 3; i <= n; i++)
	{
		result = zero + ones;
		ones = zero;
		zero = result;
	}
	
	printf("%lld", result);

	return 0;
}

