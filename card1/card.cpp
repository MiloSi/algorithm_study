#pragma warning (disable:4996)
#include <cstdio>
#include <queue>
using namespace std;
int main() {
	int n;
	queue<int> q;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		q.push(i);
	for (int i = 1; i < n; i++) {
		printf("%d ",q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d", q.front());
	return 0;
}