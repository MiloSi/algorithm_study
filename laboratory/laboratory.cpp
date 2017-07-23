//#include <iostream>
//#include <queue>
//#include <utility>
//#include <memory.h>
//using namespace std;
//
//
//int room[10][10];
//int test[10][10];
//bool isGood[10][10];
//
//
//int n, m;
//int myMaxValue;
//
//
//
//void sh0w(int n, int m) {
//
//	cout << endl;
//	for (int i = 0; i <= (n + 1); i++) {
//		for (int j = 0; j <= (m + 1); j++)
//		{
//			cout << test[i][j] << " ";
//
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//
//}
//
//
//bool tempChecked(int i, int m)
//{
//	if (room[(i / m) + 1][(i % m) + 1] == 0) {
//		room[(i / m) + 1][(i % m) + 1] = 1;
//		return true;
//	}
//	return false;
//}
//void unLock(int i, int m)
//{
//	room[(i / m) + 1][(i % m) + 1] = 0;
//}
//
//
//void bfs(int n, int m)
//{
//	queue<pair<int, int>> q;
//
//	for (int i = 0; i <= n+1; i++)
//	{
//		for (int j = 0; j <= m+1; j++)
//		{
//			test[i][j] = room[i][j];
//			if (test[i][j] == 2) {
//				pair<int, int> p = { i, j };
//				q.push(p);
//			}
//		}
//	}
//
//	while (q.size())
//	{
//		pair<int, int> p = q.front();
//		q.pop();
//		int y = p.first;
//		int x = p.second;
//	
//
//		if(y > 0)
//		if (test[y - 1][x] == 0)
//		{
//			test[y - 1][x] = 2;
//			pair<int, int> temp = { y - 1, x };
//			
//			q.push(temp);
//		}
//		if (y < n)
//		if (test[y + 1][x] == 0) {
//			test[y + 1][x] = 2;
//			pair<int, int> temp = { y + 1, x };
//			q.push(temp);
//		}
//		if(x >0 )
//		if (test[y ][x-1] == 0)
//		{
//			test[y][x-1] = 2;
//			pair<int, int> temp = { y, x -1};
//			q.push(temp);
//		}
//		if(x < m)
//		if (test[y ][x+1] == 0) {
//			test[y][x+1] = 2;
//			pair<int, int> temp = { y, x+1 };
//			q.push(temp);
//		}
//	}
//	int w = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			
//			if (test[i][j] == 0) {
//				w++;
//			}
//		}
//	}
//	if (myMaxValue < w)
//		myMaxValue = w;
//
//}
//
//int main() {
//	cin >> n >> m;
//
//
//	for (int i = 0; i <= n + 1; i++)
//		for (int j = 0; j < m + 1; j++) {
//			room[i][j] = 1;
//			isGood[i][j] = false;
//		}
//
//
//	myMaxValue = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) {
//			cin >> room[i][j];
//		}
//	}
//
//	for (int i = 0; i < n * m; i++)
//	{
//		if (!tempChecked(i, m))
//			continue;
//
//		for (int j = i + 1; j < n*m; j++)
//		{
//
//			if (!tempChecked(j, m))
//				continue;
//			for (int k = j + 1; k < n*m; k++)
//			{
//				if (!tempChecked(k, m))
//					continue;
//
//				//sh0w(n, m);
//				
//				bfs(n, m);
//
//				unLock(k, m);
//			}
//			unLock(j, m);
//		}
//		unLock(i, m);
//	}
//
//
//	cout << myMaxValue << endl;
//
//
//		
//
//	return 0;
//}
#pragma warning (disable :4996)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX_SIZE 8
#define INF 0x7fffffff

using namespace std;
//input
int map[MAX_SIZE][MAX_SIZE];
int m, n;

//process
bool visit[MAX_SIZE][MAX_SIZE];
int max_value;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

vector<pair<int, int> > virus;

void input()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
}

void copy_map(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

int recovery(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE])
{
	int ret = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0) ret++;
			a[i][j] = b[i][j];
		}
	}
	return ret;
}

void bfs()
{
	queue<pair<int, int> > q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[nx][ny] != 0) continue;

			map[nx][ny] = 2;
			q.push(make_pair(nx, ny));
		}
	}
}

void dfs(int x, int y, int d)
{
	map[x][y] = 1;
	visit[x][y] = 1;

	if (d == 3)
	{
		//bfs
		int tmp[MAX_SIZE][MAX_SIZE];
		copy_map(tmp, map);

		bfs();
		max_value = max(max_value, recovery(map, tmp));

		visit[x][y] = 0;
		map[x][y] = 0;
		return;
	}

	for (int i = x; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] || map[i][j] != 0) continue;
			dfs(i, j, d + 1);
		}
	}

	map[x][y] = 0;
	visit[x][y] = 0;
}

void process()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 0) continue;
			dfs(i, j, 1);
		}
	}

	printf("%d\n", max_value);
}

int main()
{
	input();
	process();

	return 0;
}

