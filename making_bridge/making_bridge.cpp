#pragma warning (disable : 4996)
#include <cstdio>
#include <queue>
#include <memory.h>


typedef struct _NODE {
	int y, x, w;
}node;

using namespace std;

#define LOP(i, j, n) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)

bool visited[100][100];
int islands[100][100];
int n;
int num =2 ;
int result = 0x7fff;


void check(int y, int x, queue<node>& q) {

	if (islands[y][x] == 1)
	{
		islands[y][x] = num;
		node p = { y,x,0 };
		q.push(p);
	}
}
void check(int y, int x, int type, int w, queue<node>& q) {

	if (islands[y][x] != type && !visited[y][x])
	{
		visited[y][x] = true;
		node p = { y,x, w+1};
		q.push(p);
	}
}



void dfs2(int y, int x, int type) {
	memset(visited, false, sizeof(visited));
	queue<node> q;
	node p = { y, x, 0 };
	visited[y][x] = true;
	q.push(p);

	while (q.size()) {
		node p1 = q.front();
		q.pop();
		int y = p1.y;
		int x = p1.x;
		int w = p1.w;

		if (type != islands[y][x] && islands[y][x] != 0) {
			if (result > w-1)
				result = w-1;
			break;
		}

		if (y > 0) check(y - 1, x, type, w, q);
		if (y < n - 1) check(y + 1, x, type, w, q);
		if (x > 0) check(y, x - 1, type, w, q);
		if (x < n - 1) check(y, x + 1, type, w, q);
	}
}



void dfs(int y, int x) {

	queue<node> q;
	node p = {y, x, 0};	
	islands[y][x] = num;

	q.push(p);

	while (q.size()) {
		node p1 = q.front();
		q.pop();
		int y = p1.y;
		int x = p1.x;

		if (y > 0) check(y - 1, x, q);
		if (y < n-1) check(y + 1, x, q);
		if (x > 0) check(y, x-1, q);
		if (x < n-1) check(y, x+1, q);
	}
	num++;
}



int main() {
	scanf("%d", &n);

	LOP(i, j ,n) scanf("%d", &islands[i][j]);
	LOP(i, j, n) if (islands[i][j] == 1) dfs(i, j);
	LOP(i, j, n) if (islands[i][j] != 0) { dfs2(i, j, islands[i][j]); if (result == 1) break; }

	printf("%d\n", result);

	return 0;
}