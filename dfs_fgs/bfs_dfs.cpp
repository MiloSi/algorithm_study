#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>


int table[1001][1001];
int visited[1001];
int n;


struct node {
	int n;
	struct node *next;
};

struct queue {
	struct node *prv;
	struct node *next;
	int size;
};
void initNode(struct node* n, int v) {
	n->next = NULL;
	n->n = v;

}
void initQueue(struct queue *q) {
	q->next = NULL;
	q->prv = NULL;
	q->size = 0;
}

void push(struct queue* q, int i)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	initNode(newNode, i);

	if (q->next == NULL && q->prv == NULL)
	{
		q->next = newNode;
		q->prv = newNode;
		q->size = 1;
	}
	else {
		q->next->next = newNode;
		q->next = newNode;
		q->size++;
	}

}
int pop(struct queue* q)
{
	int v = -1;
	if (q->prv->next == NULL) {
		v = q->prv->n;
		q->prv = q->next = NULL;
	}
	else if (q->prv->next != NULL) {
		struct node* n = q->prv;
		v = n->n;
		q->prv = q->prv->next;
		free(n);
	}
	q->size--;

	return v;
}


void dfs(int level) {

	int i;
	visited[level] = 1;
	printf("%d ", level);
	for (i = 1; i <= n; i++)
	{
		if (table[level][i] == 1 && visited[i] != 1) {
			dfs(i);
		}
	}
}

void bfs(int level) {
	struct queue q;
	initQueue(&q);
	push(&q, level);
	visited[level] = 1;

	while (q.size) {
		int here = pop(&q);
		printf("%d ", here);

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] != 1 && table[here][i] == 1) {
				visited[i] = 1;
				push(&q, i);
			}
		}
	}
}

int main(int argc, char** argv) {
	int i;
	int m;
	int x, y, root;

	scanf("%d %d %d", &n, &m, &root);
	
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &y, &x);
		table[y][x] = 1;
	}
	dfs(root);

	printf("\n");
	for (i = 0; i <= n; i++)
		visited[i] = 0;

	bfs(root);

	printf("\n");

	return 0;
}




