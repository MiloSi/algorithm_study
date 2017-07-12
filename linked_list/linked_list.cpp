#include <iostream>
#define N 16

using namespace std;
typedef struct _linked_list {
	struct _node* header;
	int nSize;
}linked_list;
 
typedef struct _node {
	int value;
	struct _node* next;
}node;



void inputNode(linked_list *l, int v) {
	node *n = new node();
	n->value = v;
	n->next = NULL;


	if (l->header == NULL) {
		l->header = n;
		l->nSize++;
		return;
	}

	node *header = l->header;
	node *ptr = header;
	node *temp = NULL;


	while (ptr != NULL)
	{
		if (ptr->value < v) { // move
			if (ptr->next == NULL) {
				ptr->next = n;
				l->nSize++;
				return;
			}
			temp = ptr;
			ptr = ptr->next;
		}

		else if (ptr->value > v) {
			if (ptr == header)
			{
				n->next = header;
				l->header = n;

				l->nSize++;
				return;
			}
			temp->next = n;
			n->next = ptr;
			l->nSize++;
			return;
		}
	}
}

int deleteNode(linked_list *l, int v)
{
	node *header = l->header;
	node *ptr = l->header;
	node *temp = NULL;

	while (ptr != NULL) {

		if (ptr->value < v) {
			temp = ptr;
			ptr = ptr->next;
			continue;
		}

		if (ptr->value == v) {
			if (ptr == header)
			{
				temp = header;
				l->header = ptr->next;
				delete temp;

				return 1;
			}
			else if (ptr->next == NULL) {
				temp->next = NULL;
				delete ptr;

				return 1;
			}
			temp->next = ptr->next;
			delete ptr;

			return 1;
		}
		if (ptr->value > v)
			break;

	}

	return 0;


}
void deleteAll(linked_list *l) {
	node *ptr = l->header;
	node *temp;

	while (ptr != NULL) {
		temp = ptr;
		ptr = ptr->next;
		delete temp;
	}


}
void show(linked_list *l) {
	node *ptr = l->header;

	while (ptr != NULL)
	{
		printf("%d ", ptr->value);
		ptr = ptr->next;
	}

	cout << endl;
}
int main() {
	linked_list l;

	l.header = NULL;
	l.nSize = 0;
	
	int arr[N] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6, 9, 64, 16, 12 };
	for (int i = 0; i < N; i++)	{
		inputNode(&l, arr[i]);
	}

	show(&l);
	cout << deleteNode(&l, 1) << endl;
	cout << deleteNode(&l, 64) << endl;
	cout << deleteNode(&l, 19) << endl;
	cout << deleteNode(&l, 18) << endl;

	inputNode(&l, 0);

	show(&l);
	
	deleteAll(&l);
}