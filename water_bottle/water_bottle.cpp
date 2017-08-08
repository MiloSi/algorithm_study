#include <iostream>
#include <queue>
using namespace std;
bool visited[3][201];
bool result[201];
typedef struct _Node {
	int bottle[3];
}Node;
int bottle_size[3];
int from[6] = { 0,0,1,1,2,2 };
int to[6] = { 1,2,0,2,0,1 };
void pour_water(Node n, int* b_size, queue<Node> &q, int f, int t ) {
	int b1 = n.bottle[f];
	int b2 = n.bottle[t];
	if (b_size[t] - n.bottle[t] < n.bottle[f])
	{
		b1 -= (b_size[t] - b2);
		b2 = b_size[t];
	}
	else {
		b2 += b1;
		b1 = 0;
	}	
	Node node;
	for (int i = 0; i < 3; i++) {
		if (i == f)
			node.bottle[i] = b1;
		else if (i == t)
			node.bottle[t] = b2;
		else
			node.bottle[i] = n.bottle[i];
	}
	bool isOkay = false;
	for (int i = 0; i < 3; i++) {
		if (!visited[i][node.bottle[i]]) {
			isOkay = true;
			visited[i][node.bottle[i]] = true;
		}
	}
	if (isOkay) {
		q.push(node);
	}
	if (node.bottle[0] == 0)
		result[node.bottle[2]] = true;

}
void bfs() {
	queue<Node> q;
	result[bottle_size[2]] = true;
	Node n = { 0,0, bottle_size[2] };
	
	for (int i = 0; i < 3; i++) {
		visited[i][n.bottle[i]] = true;
	}
	q.push(n);
	while (q.size()) {
		n = q.front();		
		q.pop();
		for (int i = 0; i < 6; i++) {
			if(n.bottle[from[i]] != 0) pour_water(n, bottle_size, q, from[i], to[i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> bottle_size[0] >> bottle_size[1] >> bottle_size[2];
	bfs();
	for (int i = 0; i <= bottle_size[2]; i++) {
		if (result[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}