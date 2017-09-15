#pragma warning (disable : 4996)
#include <cstdio>
int arr[2000];
bool dp[2000][2000];


int main() {
	int n, m;
	int y, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int l_ptr, r_ptr;
	bool checked; 
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			l_ptr = i;
			r_ptr = j;
			checked = true;
			if (dp[i][j]) continue;
			while (l_ptr < r_ptr) {
				if (arr[l_ptr] != arr[r_ptr]) {
					checked = false;
					break;
				}
				l_ptr++;
				r_ptr--;
			}
			if (checked) {
				l_ptr = i;
				r_ptr = j;
				while (l_ptr <= r_ptr) {
					dp[l_ptr][r_ptr] = true;
					l_ptr++;
					r_ptr--;
				}
			}
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &y, &x);
		if (dp[y - 1][x - 1])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}