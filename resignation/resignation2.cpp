#include <iostream>
#include <memory.h>
using namespace std;

int schedules[17];

struct DAY {
	int t;
	int p;
}days[16];


int main() {
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> days[i].t >> days[i].p;
	}


	memset(schedules, 0, sizeof(schedules));


	if (1 + days[1].t <= n+1)
		schedules[1 + days[1].t] = days[1].p;
	
	for (int i = 2; i <= n + 1; i++)
	{
		if (schedules[i] < schedules[i - 1])
			schedules[i] = schedules[i - 1];


		if (i + days[i].t <= n + 1) {
			if (schedules[i + days[i].t] < schedules[i] + days[i].p)
				schedules[i + days[i].t] = schedules[i] + days[i].p;
		}
	

	}
	cout << schedules[n+1] << endl;

	return 0;

}