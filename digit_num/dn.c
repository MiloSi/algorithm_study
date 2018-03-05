#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int NUM_MAX = 20;
int firstProcess(const char* input) {
	int sum = 0;
	int len = strlen(input);
	for (int i = 0; i < len; ++i) {
		int tmp = input[i] - '0';
		sum += tmp;
	}
	return sum;
}
int secondProcess(int val) {
	int retval = val % 9;
	if (retval == 0 && val > 0) retval = 9;
	return retval;
}
int solution() {
	char* input;
	input = (char*)malloc(NUM_MAX * sizeof(char));
	scanf("%s", input);
	int val = firstProcess(input);
	free(input);
	return secondProcess(val);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		printf("#%d %d\n", test_case, solution());
	}
	return 0;
}
