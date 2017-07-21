#include <iostream>
#include <memory.h>
using namespace std;

int schedules[17][17];

struct DAY {
	int t;
	int p;
}days[15];


int Max(int i) {
	int max = 0;
	for (int k = 1; k <= i; k++) {
		if (max < schedules[i][k])
			max = schedules[i][k];
	}
	return max;
}


int main() {
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> days[i].t >> days[i].p;
	}


	memset(schedules, 0, sizeof(schedules));


	if (1 + days[0].t <= n+1)
		schedules[1 + days[0].t][1] = days[0].p;
	
	for (int i = 2; i <= n+1; i++)
	{
		int m = Max(i - 1);

		for (int j = 0; j < i; j++) {

			if (schedules[i][j] == 0) {
				schedules[i][j] = m;
			}
		}

		if (days[i-1].t + i <= n+1) {
			schedules[i + days[i-1].t][i] = Max(i) + days[i-1].p;
		}
	}
	int max = 0;

	max = Max(n+1);
	cout << max << endl;

	return 0;

}