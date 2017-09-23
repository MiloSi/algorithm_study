#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

double seven[7];
int idx = 0;
int n;


priority_queue<double> pq;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double d;
		scanf("%lf", &d);

		if (pq.size() == 7) {
			if (pq.top() < d) continue;
			else {
				pq.pop();
				pq.push(d);
			}
		}
		else {
			pq.push(d);
		}
	}
	for (int i = 6; i >= 0; i--) {
		seven[i] = pq.top();
		pq.pop();
	}
	for (int i = 0; i < 7; i++) {	
		printf("%.3lf\n", seven[i]);
	}
	return 0;
}