#include <iostream>
using namespace std;

bool box[101][101];



typedef struct _QueueNode {
	_QueueNode *next;
	int y;
	int x;
}qNode;
typedef struct _Queue{
	_QueueNode* front;
	_QueueNode* rear;
	int nSize;
}queue;


typedef struct _Node {
	_Node *next;
	int v;
}node;
typedef struct _Linked_List {
	_Node *header;
	int nSize;
}linkedList;


void init(linkedList* l) {


	l->header = NULL;
	l->nSize = 0;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			box[i][j] = 1;
}

void initQueue(queue * q)
{
	q->front = q->rear = NULL;
	q->nSize = 0;
}



void push(queue* q, int y, int x) {
	qNode* n = new qNode();
	n->next = NULL;
	n->y = y;
	n->x = x;

	q->nSize++;
	if (q->rear == NULL && q->front == NULL)
	{
		q->rear = q->front = n;
		return;
	}
	q->rear->next = n;
	q->rear = n;
}
int pop(queue* q)
{
	int v;
	if (q->nSize == 0)
		return -1;

	qNode* n = q->front;
	if (q->front->next == NULL)
	{
		v = q->front->x + q->front->y * 100;
		q->front = q->rear = NULL;
		q->nSize--;
		delete n;
		return v;
	}


	v = (n->y * 100) + n->x;
	q->front = q->front->next;
	q->nSize--;
	

	return v;
}

void linking(linkedList* l, int v) {
	node *newNode = new node();
	newNode->v = v;
	newNode->next = NULL;

	if (l->header == NULL) {
		l->header = newNode;
		l->nSize++;
		return;
	}

	node *ptr = l->header;
	node *temp = NULL;

	while (ptr != NULL) {
		if (ptr->v >= v) //stop
		{
			if (ptr == l->header)
			{
				l->header = newNode;
				l->header->next = ptr;
				l->nSize++;
				break;
			}
			temp->next = newNode;
			newNode->next = ptr;
			l->nSize++;
			break;
			
		}
		else {
			if (ptr->next == NULL) {
				ptr->next = newNode;
				l->nSize++;
				break;
			}
			temp = ptr;
			ptr = ptr->next;
		}
	}
}



void rectangle(int x1, int y1, int x2, int y2)
{
	for (int y = y1; y < y2; y++)
	{
		for (int x = x1; x < x2; x++)
		{
			box[y][x] = 0;
		}
	}
}

int bfs(int y, int x, int rows, int cols) {
	queue q;
	int rSize = 0;
	initQueue(&q);
	push(&q, y, x);
	box[y][x] = 0;

	while (q.nSize) {
		rSize++;
		int v = pop(&q);
		if (v == -1)
			break;
		y = v / 100;
		x = v % 100;

		if (x > 0) {
			if (box[y][x - 1]) {
				box[y][x - 1] = 0;
				push(&q, y, x - 1);
			}
		}
		if (x < cols-1) {
			if (box[y][x + 1]) {
				box[y][x + 1] = 0;
				push(&q, y, x + 1);
			}
		}
		if (y > 0) {
			if (box[y-1][x]) {
				box[y-1][x] = 0;
				push(&q, y-1, x );
			}
		}
		if (y < rows-1) {
			if (box[y + 1][x]) {
				box[y + 1][x] = 0;
				push(&q, y + 1, x);
			}
		}
	}
	return rSize;
}

void show(linkedList* l)
{

	node* ptr = l->header;
	node* temp = NULL;
	while (l->nSize) {
		temp = ptr;
		printf("%d ", temp->v);
		ptr = ptr->next;
		l->nSize--;
		delete temp;
	}
}


void showTable(int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (box[i][j])
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}


int main() {
	int n, m, k;
	int x1, y1, x2, y2;
	int total = 0;

	linkedList l;

	init(&l);

	cin >> m >> n  >> k;

	//n == cols, m == rows 

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		rectangle(x1, y1, x2, y2);
	}

	showTable(m, n);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (box[i][j]) {
				linking(&l, bfs(i, j, m, n));
				total++;

				showTable(m,n);
			}
		}
	}
	printf("%d\n", total);
	show(&l);
}