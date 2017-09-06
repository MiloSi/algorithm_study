#pragma warning (disable : 4996)
#include <cstdio>
#include <cstring>
char str[1000001];
int pi[1000000];
int main() {
	while (true) {
		scanf("%s", str);
		if (strstr(str, ".")) break;
		int len = strlen(str);
		for (int i = 1, j = 0; i < len; i++) {
			while(j > 0 && str[i] != str[j]) j = pi[j - 1];
			if (str[i] == str[j]) pi[i] = ++j;
			else pi[i] = 0;
		}
		int k = pi[len - 1];
		int result = 1;
		while (k > 0) {
			if (pi[k-1] < pi[k]) {
				result++;
				k = pi[k-1];
			}
			else break;
		}
		printf("%d\n",result);

	}
	return 0;
}