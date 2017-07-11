#include <iostream>

using namespace std;


int table[1000][1000];
int queue[1000001];
int weight[1000001];
int visited[1000][1000];

int rear = -1;
int front = -1;
int nSize = 0;

int answer = 0;


void push(int x)
{
	nSize++;
	queue[++rear] = x;
	
}

int pop() {
	if (nSize <= 0)
		return -2;
	nSize--;
	return queue[++front];
}

void pushWeight(int x) {
	weight[rear] = x;
}
int popWeight() {

	return weight[front];
}

void bfs(int rows , int cols) {


	answer = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (table[i][j] == 1)
			{
				push((i * 1000) + j);
				visited[i][j] = 1;
				pushWeight(0);
				continue;
			}
			answer = 0;
		}
	}

	if (answer == 1)
		return;

	while (nSize) {
		int v = pop();
		int w = popWeight();

		if (answer < w)
			answer = w;

		int x = v % 1000;
		int y = v / 1000;


		if (y > 0)
			if (visited[y - 1][x] == 0 && table[y - 1][x] == 0) {
				table[y - 1][x] = 1;
				visited[y - 1][x] = 1;
				push((y - 1) * 1000 + x);
				pushWeight(w + 1);

			}
		if (x > 0)
			if (visited[y][x - 1] == 0 && table[y][x - 1] == 0) {
				table[y][x - 1] = 1;
				visited[y][x - 1] = 1;
				push(y * 1000 + (x - 1));
				pushWeight(w + 1);
			}
		if (y < rows - 1)
			if (visited[y + 1][x] == 0 && table[y + 1][x] == 0) {
				table[y + 1][x] = 1;
				visited[y + 1][x] = 1;
				push((y + 1) * 1000 + x);
				pushWeight(w + 1);
			}
		if (x < cols - 1)
			if (visited[y][x + 1] == 0 && table[y][x + 1] == 0) {
				table[y][x + 1] = 1;
				visited[y][x + 1] = 1;
				push(y * 1000 + (x + 1));
				pushWeight(w + 1);
			}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (table[i][j] == 0)
			{
				answer = -1;
				return;
			}
		}
	}

}


int main()
{
	int m, n;

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> table[i][j];
		}
	}

	bfs(n, m);

	cout << answer << endl;

	return 0;
}