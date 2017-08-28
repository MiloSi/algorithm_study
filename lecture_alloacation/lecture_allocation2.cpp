#pragma warning (disable : 4996)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef struct _Node { 
	int st, ed;
	const bool operator < (const _Node &n) {
		if (this->st == n.st) {
			return this->ed < n.ed;
		}
		return st < n.st;
	}
	/*
	int operator + (const _Node &n) {
		return this->st + n.st;
	}
	void operator = (int a) {
		this->st = a;
	}*/
}Node;

struct myGreater {
	bool operator()(int a, int b) {
		return a > b;
	}
};
// n size <= 200,000
Node node[200001];
priority_queue<int, vector<int>, myGreater> pq;
int n, result;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &node[i].st, &node[i].ed);
	}
	sort(node, node + n);
	pq.push(node[0].ed);
	for (int i = 1; i < n; i++){
		int a = pq.top();
		if (a <= node[i].st) pq.pop();
		pq.push(node[i].ed);
	}
	printf("%d\n", pq.size());

	system("pause");
	return 0;
}