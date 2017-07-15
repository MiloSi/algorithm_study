#include <iostream>
using namespace std;

bool board[301][301];

typedef struct _Node {
	_Node *next;
	int v;
	int weight;
}node;


typedef struct _Queue {
	node* front;
	node* rear;
	int nSize;
}queue;


void push(queue *q, int v, int w) {
	node* n = new node();
	n->v = v;
	n->weight = w;
	n->next = NULL;

	if (q->front == NULL && q->rear == NULL) {
		q->front = q->rear = n;
		q->nSize++;
		return;
	}

	q->rear->next = n;
	q->rear = n;
	q->nSize++;
	return;
}

int pop(queue* q) {
	if (q->nSize == 0)
		return -1;

	node* n = q->front;
	int v = n->v;
	if (q->front->next == NULL) {
		q->front = q->rear = NULL;
	}
	else {
		q->front = q->front->next;
	}
	q->nSize--;
	delete n;
	return v;
}
int popWeight(queue *q) {
	return q->front->weight;
}


void initBoard(int n) {
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = true;
}
void initQueue(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->nSize = 0;
}

void isMove(int x, int y, int n, queue* q, int w) {
	if (board[y][x]) {
		board[y][x] = false;
		push(q, y*n + x, w);
	}
}


int bfs(int x, int y, int toX, int toY, int n)
{
	int answer = 0;
	queue q;
	initQueue(&q);
	board[y][x] = false;
	push(&q, y*n + x, 0);

	while (q.nSize)
	{
		
		int w = popWeight(&q);
		int v = pop(&q);
		
		x = v % n;
		y = v / n;

		if (x == toX && y == toY)
			return w;
		if (x > 0 && y > 1) isMove(x - 1, y - 2, n, &q, w+1);
		if (x > 0 && y < n-2) isMove(x - 1, y + 2, n, &q, w + 1);
		if (x < n-1 && y > 1) isMove(x + 1, y - 2, n, &q, w + 1);
		if (x < n-1 && y < n-2) isMove(x + 1, y + 2, n, &q, w + 1);
		if (x > 1 && y > 0) isMove(x - 2, y - 1, n, &q, w + 1);
		if (x > 1 && y < n-1) isMove(x - 2, y + 1, n, &q, w + 1);
		if (x < n-2 && y > 0) isMove(x + 2, y - 1, n, &q, w + 1);
		if (x < n-2 && y < n-1) isMove(x + 2, y + 1, n, &q, w + 1);
	}
}




int main() {
	int t, n, fromX, fromY, toX, toY;

	cin >> t;



	for (int sequence = 0; sequence < t; sequence++)
	{

		cin >> n;
		initBoard(n);
		
		cin >> fromX >> fromY;
		cin >> toX >> toY;
	
		cout << bfs(fromX, fromY, toX, toY, n) << endl;
	}

	return 0;
}
