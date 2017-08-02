#include <iostream>
#include <queue>
#include <utility>
#include <array>
using namespace std;
array<array<int, 300>, 300> arr;
array<array<int, 300>, 300> melts = { 0, };
array<array<bool, 300>, 300> visited;
int n, m;
int height = 0;

int yv[4] = { 1,-1,0,0 };
int xv[4] = { 0,0,-1,1 };


void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));
	visited[y][x] = true;

	while (q.size()) {

		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			y = p.first + yv[i];
			x = p.second + xv[i];
			if (arr[y][x]) {
				if (!visited[y][x]) {
					visited[y][x] = true;
					q.push(pair<int, int>(y, x));
				}
			}
			else {
				melts[p.first][p.second]++;
			}
		}
	}
}
int search() {
	int year = 0;
	int num, _Min = 10, _Max = 0;

	while(_Min != _Max) {
		num = 0;
		_Min = 10;
		_Max = 0;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				arr[i][j] -= melts[i][j];
				melts[i][j] = 0;
				visited[i][j] = false;


				if (arr[i][j] < 0) arr[i][j] = 0;
				if (_Min > arr[i][j]) _Min = arr[i][j];
				if (_Max < arr[i][j]) _Max = arr[i][j];
			}
		}
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < m-1; j++) {	
				if (!visited[i][j] && arr[i][j]) {
					num++;
					if (num == 2) {
						return year;
					}
					bfs(i, j);
				}
			}
		}
		if (_Min == _Max)
			return 0;

		year++;
	}
	return 0;
}

int main() {
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	result = search();
	if (result == 10)
		cout << 0 << endl;
	else
		cout << result << endl;

	return 0;
}