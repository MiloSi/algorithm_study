#include <iostream>
#include <array>
#include <queue>
using namespace std;

typedef struct _NODE {
	int x;
	int w;
}node;

int f, s, g, u, d;
int result = -1;
array<bool, 1000001> floors;

void bfs() {
	queue<node> q;
	floors[s] = true;
	
	
	if (s == g) {
		result = 0;
		return;
	}
	node nd = { s, 0 };
	node next;
	node current;
	q.push(nd);



	while (q.size()) {
		current = q.front();
		q.pop();

		int upNext = current.x + u;
		int downNext = current.x - d;

		if (g == upNext || g == downNext)	{
			result = current.w + 1;
			return;
		}

		if (upNext < f) if (!floors[upNext]) { 
			floors[upNext] = true;
			next = { upNext, current.w + 1 };
			q.push(next);
		}
		if (downNext > 0) if (!floors[downNext]) {
			floors[downNext] = true; 
			next = { downNext, current.w + 1 };
			q.push(next);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> f >> s >> g >> u >> d;
	bfs();


	if (result == -1)
		cout << "use the stairs" << endl;
	else 
		cout << result << endl;

	return 0;
}