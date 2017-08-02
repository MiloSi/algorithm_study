#pragma warning(disable : 4996)
#include <cstdio>
typedef struct _Node {
	int y, x;
	int b;
	struct _Node *next = NULL;
}node;
typedef struct _Queue {
	node *front = NULL;
	node *rear = NULL;
	int _Size = 0;
}queue;
queue q;
void push(int y, int x, int b) {
	node* nd = new node();
	nd->y = y; nd->x = x; nd->b = b;
	if (q.front == NULL) {
		q.front = q.rear = nd;
		q._Size++;
	}
	else {
		q.rear->next = nd;
		q.rear = q.rear->next;
		q._Size++;
	}
}
node* pop() {
	node* nd = q.front;
	if (q.front->next == NULL) {
		q.front = q.rear = NULL;
	}
	else {
		q.front = q.front->next;
	}
	q._Size--;
	return nd;
}
int result = -1;
int n, m;
int xM[4] = { 0, 0, -1,1 };
int yM[4] = { -1,1,0,0 };
char arr[1000][1001];
bool visited[2][1000][1000];
#define LOP(i,k,l) for(int i = k; i <= l; i++)
bool isOkay(int y, int x) {
	if (y >= 0 && y <= n-1 && x >= 0 && x <= m-1)
		return true;
	return false;
}
void moved(int y, int x, int b) {
	if (arr[y][x] == '0'&& !visited[b][y][x]) {
		visited[b][y][x] = true;
		push(y, x, b);
	}
	if (arr[y][x] == '1' && !visited[1][y][x] && b == 0) {
		visited[1][y][x] = true;
		push(y, x, 1);
	}
}
void bfs() {
	int y, x, b, w = 1, q_size;
	visited[0][0][0] = true;
	push(0, 0, 0);

	while (q._Size) {
		q_size = q._Size;
		while (q_size--) {
			node* nd = pop();
			if (nd->y == n-1 && nd->x == m-1) {
				result = w;
				return;
			}
			LOP(i, 0, 3) {
				y = nd->y +yM[i];
				x = nd->x +xM[i];
				b = nd->b;
				if (isOkay(y, x)) {
					moved(y, x, b);
				}
			}
			delete nd;
		}
		w++;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	LOP(i, 0, n-1) {
		scanf("%s", arr[i]);
	}
	bfs();
	printf("%d\n", result);
	return 0;
}