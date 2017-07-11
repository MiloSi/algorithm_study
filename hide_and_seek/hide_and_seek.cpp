#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

int result;
int visited[1000001];

struct node {
	int v;
	int number;
	struct node* next;
};
struct queue {
	int size;
	struct node *back;
	struct node *front;
};

void init(struct queue * q)
{
	q->front = NULL;
	q->back = NULL;
	q->size = 0;
}

void push(struct queue* q, int v, int number) {
	struct node *n = new struct node();
	n->next = NULL;
	n->number = number;
	n->v = v;

	if (q->front == NULL && q->back == NULL) {
		q->front = n;
		q->back = n;
	}
	else {
		q->back->next = n;
		q->back = n;
	}
	q->size++;
}

int pop(struct queue* q) {

	if (q->size == 0)
		return -1;
	int v;
	struct node* n;
	if (q->front->next == NULL) {
		n = q->front;
		v = q->front->v;
		q->front = q->back = NULL;
	}
	else {
		n = q->front;
		v = n->v;
		q->front = q->front->next;
	}
	delete n;
	q->size--;
	return v;
}
int popNumber(struct queue* q) {
	return q->front->number;
}

void clear(struct queue* q) {
	
	while (q->size) {
		int i = pop(q);
	}

}

void bfs(int x, int y) {

	struct queue q;
	init(&q);
	push(&q, x, 0);
	visited[x] = 1;

	while (q.size) {

		int number = popNumber(&q);
		int v = pop(&q);

		if (v == y) {
			result = number;
			clear(&q);
			
			break;
		}

		if (visited[v + 1] != 1 && v + 1 <= 200000) {
			visited[v + 1] = 1;
			push(&q, v+1, number+1);
		}
		if (visited[v - 1] != 1 && v - 1 <= 200000 && v-1 >= 0) {
			visited[v - 1] = 1;
			push(&q, v - 1, number + 1);
		}
		if (visited[v*2] != 1 && v*2 <= 200000) {
			visited[v*2] = 1;
			push(&q, v*2, number + 1);
		}
	}
}
int main() {
	int n, m;
	for (int i = 0; i <= 200000; i++)
		visited[i] = 0;
	
	scanf("%d %d", &n, &m);
	bfs(n, m);


	printf("%d\n", result);

}