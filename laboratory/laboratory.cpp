#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;


int room[10][10];
int test[10][10];
int n, m;
int maxValue;



bool tempChecked(int i, int n)
{
	if (room[(i / n) + 1][(i % n) + 1] == 0) {
		room[(i / n) + 1][(i % n) + 1] = 1;
		return true;
	}
	return false;
}
void unLock(int i, int m)
{
	room[(i / m) + 1][(i % m) + 1] = 0;
}


void bfs(int n, int m)
{
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			test[i][j] = room[i][j];
			if (test[i][j] == 2) {
				pair<int, int> p = { i, j };
				q.push(p);
			}
		}
	}

	while (!q.size())
	{
		pair<int, int> p = q.front();
		q.pop();


		int y = p.first;
		int x = p.second;
	
		if (test[y - 1][x] == 0)
		{
			test[y - 1][x] = 2;
			pair<int, int> temp = q.front();
			temp.first = y - 1;
			temp.second = x;
			q.push(temp);
		}
		if (test[y + 1][x] == 0) {
			test[y + 1][x] = 2;
			pair<int, int> temp = q.front();
			temp.first = y + 1;
			temp.second = x;
			q.push(temp);
		}
		if (test[y ][x-1] == 0)
		{
			test[y][x] = 2;
			pair<int, int> temp = q.front();
			temp.first = y ;
			temp.second = x-1;
			q.push(temp);
		}
		if (test[y ][x+1] == 0) {
			test[y][x] = 2;
			pair<int, int> temp = q.front();
			temp.first = y ;
			temp.second = x+1;
			q.push(temp);
		}
	}
	int w = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			
			if (test[i][j] == 0) {
				w++;
			}
		}
	}
	if (maxValue < w)
		maxValue = w;

}




int main() {
	cin >> n >> m;

	memset(room, 1, sizeof(room));
	maxValue = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> room[i][j];
		}
	}

	for (int i = 0; i <= n * m; i++)
	{
		if (!tempChecked(i, m))
			continue;

		for (int j = i + 1; j <= n*m; j++)
		{

			if (!tempChecked(j, m))
				continue;
			for (int k = j + 1; k <= n*m; k++)
			{
				if (!tempChecked(k, m))
					continue;
				
				bfs(n, m);

				unLock(k, m);
			}
			unLock(j, m);
		}
		unLock(i, m);
	}


	cout << maxValue << endl;


		

	return 0;
}