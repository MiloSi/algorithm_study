#include <iostream>

using namespace std;

#define MAX_SIZE 25

bool table[MAX_SIZE][MAX_SIZE];
//bool visited[25][25];

int queue[MAX_SIZE * MAX_SIZE];
int arr[MAX_SIZE * MAX_SIZE];
int rear = -1;
int front = -1;
int nSize = 0;






void push(int v)
{
	nSize++;
	queue[++rear] = v;
}
int pop()
{
	nSize--;
	return queue[++front];
}

void checked(int y, int x)
{
	if (table[y][x]) {
		table[y][x] = 0;
		push(y * 25 + x);
	}

}


int dfs(int y, int x, int rows, int cols) {

	int houseSize = 0;
	table[y][x] = 0;
	push(y * MAX_SIZE + x);

	while(nSize)
	{
		int v = pop();
		houseSize++;
		y = v / MAX_SIZE;
		x = v % MAX_SIZE;

		if (x > 0)			checked(y, x - 1);
		if (x < cols - 1)	checked(y, x + 1);
		if (y > 0)			checked(y - 1, x);
		if (y < rows - 1)	checked(y + 1, x);

	}

	return houseSize;
}

void insertSort(int index)
{

	int t;
	int j;
	for (int i = 1; i < index; i++)
	{
		t = arr[i];
		for (j = i -1; j >= 0; j--)
		{
			if (arr[j] > t) arr[j + 1] = arr[j];
			else break;
		
		}
		arr[j+1] = t;
	}
}


int main() {
	int n;
	char str[MAX_SIZE + 1];
	int number = 0;
	int index = 0;;


	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			table[i][j] = str[j] - 48;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (table[i][j]) {
				number++;
				arr[index++] = dfs(i, j, n, n);
			}
		}
	}
	insertSort(index);
	printf("%d\n", number);

	for (int i = 0; i < index; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;

}