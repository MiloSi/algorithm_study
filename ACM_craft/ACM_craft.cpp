#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

//(topological sorting)
//please restudy again
using namespace std;
int cost[1001];
bool checked[1001];
bool table[1001][1001];

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

typedef struct _Edge {
	int to;
	struct _Edge* next;
}edge;


typedef struct _Node {
	struct _Edge* header = NULL;
}node;
node nodes[1001];

vector<int> sequence;




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

void bfs(int start, int n) {
	checked[start] = true;
	int mx = cost[start];

	for (int i = 1; i <= n; i++)
	{
		if (checked[i] == false && table[start][i]) {
			bfs(i, n);
		}
	}
	sequence.push_back(start);
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


		memset(checked, false, sizeof(checked));
		memset(table, false, sizeof(table));

		//sequence.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> cost[i];
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			insert(y, x);
			table[x][y] = true;
		}
		cin >> start;

		for (int i = 1; i <= n; i++) {
			if(!checked[i])
				bfs(i, n);
		}
		reverse(sequence.begin(), sequence.end());

		for (int i = 0; i < sequence.size(); i++ ) {
			int index = sequence[i];
			int values = cost[index];

			edge* e = nodes[index].header;

			int edgeMax = 0;

			while (e != NULL) {
				int from = e->to;

				if (edgeMax < cost[from])
					edgeMax = cost[from];

				e = e->next;
			}
			cost[index] = cost[index] + edgeMax;
		}


		cout << cost[start] << endl;
		sequence.clear();
		clear(n);

	}
	return 0;
}
