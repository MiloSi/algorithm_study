#pragma warning (disable : 4996)
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
#define PI pair<int,int>
#define PIC pair<int,char>
bool apples[101][101];

vector<PIC> orders;
int n, k, l;
int dy[4] = { -1,0, 1,0 };
int dx[4] = { 0,1,0,-1 };
int dir = 1;

typedef struct _NODE {
	int y, x, d;
	struct _NODE* next;
	struct _NODE* prev;
}Node;
typedef struct LINKED_LIST {
	Node *header;
	Node *tail;
}List;
List  m_list;
int m_Count = 0;
inline PI _Sort(int a, int b) {
	PI p;
	if (a < b) p = { a,b };
	else p = { b, a };
	return p;
}
void init() {
	Node* nd = new Node();
	nd->y = 1;
	nd->x = 1;
	nd->d = dir;
	nd->next = NULL;
	nd->prev = NULL;
	m_list.header = nd;
	m_list.tail = NULL;
}
bool move() {
	int y = m_list.header->y += dy[dir];
	int x = m_list.header->x += dx[dir];
	m_Count++;
	if (y > n || y < 1 || x > n || x < 1) return false;
	int fy, fx, tx, ty;
	PI px, py;

	Node *header = m_list.header->next;
	if (header != NULL) {
		while (header->next != NULL) {
			fy = header->y;
			fx = header->x;
			header = header->next;
			ty = header->y;
			tx = header->x;
			px = _Sort(fx, tx);
			py = _Sort(fy, ty);

			if (px.first <= x && x <= px.second && py.first <= y && y <= py.second) return false;
		}
	}


	if (apples[y][x]) {
		apples[y][x] = false;
		if (m_list.tail == NULL) {
			Node* nd = new Node();
			nd->x = x - dx[dir];
			nd->y = y - dy[dir];
			nd->d = dir;
			nd->prev = m_list.header;
			nd->next = NULL;
			m_list.header->next = nd;
			m_list.tail = nd;
		}
	}
	else if (m_list.tail != NULL) {
		m_list.tail->y += dy[m_list.tail->d];
		m_list.tail->x += dx[m_list.tail->d];
		if (m_list.tail->prev != m_list.header) {
			if (m_list.tail->y == m_list.tail->prev->y && m_list.tail->x == m_list.tail->prev->x) {
				Node * nd = m_list.tail;
				m_list.tail = m_list.tail->prev;
				m_list.tail->next = NULL;
				delete nd;
			}
		}
	}

	
	return true;
}
void turn(int t) {
	if (t == 0)
		dir = (dir + 1) % 4;
	else
		dir = (dir + 3) % 4;
	if (m_list.tail != NULL) {
		Node *nd = new Node();
		nd->x = m_list.header->x;
		nd->y = m_list.header->y;
		nd->d = dir;

		m_list.header->next->prev = nd;
		nd->next = m_list.header->next;
		m_list.header->next = nd;
		nd->prev = m_list.header;
	}
}


int main() {
	scanf("%d%d", &n, &k);
	int y, x;
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &y, &x);
		apples[y][x] = true;
	}
	scanf("%d", &l);
	orders.resize(l);
	for (int i = 0; i < l; i++) {
		PIC p;
		scanf("%d %c", &p.first, &p.second);
		orders[i] = p;
	}
	
	init();
	int m = 0;
	int s = 0;
	for (int i = 0; i < l; i++) {
		m = orders[i].first;
		for (s; s < m; s++) {
			if (!move()) {
				printf("%d\n", m_Count);
				return 0;
			}
		}
		if (orders[i].second == 'D')
			turn(0);
		else
			turn(1);
	}
	m = 2001;
	for (int j = 0; j < m; j++) {
		if (!move()) {
			printf("%d\n", m_Count);
			return 0;
		}
	}
	return 0;
}
