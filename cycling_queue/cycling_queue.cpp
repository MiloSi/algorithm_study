#pragma warning (disable:4996)
#include <cstdio>
int n, m, x;
typedef struct _Node{
	int i;
	struct _Node *next = NULL;
	struct _Node *prev = NULL;
}Node;
typedef struct _Header {
	 Node *header =  NULL;
}Header;
Header h;

int main() {
	int idx = 0;
	scanf("%d%d", &n, &m);

	{
		Node* nd = new Node;
		nd->i = 1;
		h.header = nd;
		Node* prev = nd;
		for (int i = 2; i <= n; i++) {
			Node* nd = new Node;
			nd->i = i;
			prev->next = nd;
			nd->prev = prev;
			prev = nd;
		}
		h.header->prev = prev;
		prev->next = h.header;
	}
	int sequence = 0;
	Node* nd = h.header;
	Node *prev, *next;

	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		next = prev = nd;
	
		while (prev->i != x && next->i != x) {
			prev = prev->prev;
			next = next->next;	
			sequence++;
		}
		if (prev->i == x) {
			nd = prev;
		}
		else {
			nd = next;
		}
		next = nd->next;
		prev = nd->prev;
		prev->next = next;
		next->prev = prev;
		delete nd;
		nd = next;
	}
	printf("%d\n", sequence);



}