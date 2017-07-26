#pragma warning (disable : 4996)
#include<cstdio>

int main() {
	int t, n;
	long long w[101] = {0,};

	scanf("%d", &t);

	w[1] = 1;
	w[2] = 1;
	w[3] = 1;
	w[4] = 2;

	for (int i = 5; i <= 100; i++)
	{
		w[i] = w[i - 1] + w[i - 5];
	}

	for (int testcase = 0; testcase < t; testcase++) {
		scanf("%d", &n);

		printf("%lld\n", w[n]);


	}

	return 0;
}