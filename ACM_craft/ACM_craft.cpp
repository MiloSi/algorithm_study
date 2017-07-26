#include <iostream>
#include <memory.h>
using namespace std;


int cost[1001];


inline int MAX(int a, int b) {
	return a > b ? a : b;
}

typedef struct _Edge {
	int to;
	struct _Edge* next;
}edge;


typedef struct _Node {
	struct _Edge* header =NULL;
}node;

node nodes[1001];

void insert(int i, int to) {
	edge *e = new edge();

	e->to = to;
	e->next = NULL;

	edge *h = nodes[i].header;

	if (h == NULL) {
		nodes[i].header = e;
		return;
	}
	while (h->next != NULL) h = h->next;
	h->next = e;
}
void clear(int n) {
	for (int i = 1; i <= n; i++)
	{
		edge* e = nodes[i].header;
		if (e == NULL)
			continue;
		edge *temp = NULL;
		while (e != NULL) {
			temp = e;
			e = e->next;
			delete temp;
		}
		nodes[i].header = NULL;
	}
}

int bfs(int start, int n) {

	int mx = cost[start];

	edge *h = nodes[start].header;

	while (h != NULL) {
		mx = MAX(bfs(h->to, n) + cost[start], mx);
		h = h->next;
	}

	return mx;
}

int main() {
	int t, n, k;
	int x, y, start;
	int result;


	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		result = 0;
		cin >> n >> k;

		for(int i = 1; i <= n; i++)
			cin >> cost[i];
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			insert(y, x);
		}

		cin >> start;
		result = bfs(start, n);


		cout << result << endl;

		clear(n);

	}
	return 0;
}