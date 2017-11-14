#include <iostream>
#include <queue>
#include <utility>
using namespace std;
struct Node {
	int left, right, level = 0;
	int leftL = 0, rightL = 0;

};
void rightTree(int idx, int loc, int level);
void leftTree(int idx, int loc, int level);
int n, v, x, y;
int mxLevel = 0;
int depth = 0, length = 0;
bool findRoot[10001];
int location[10001];
pair<int, int> p[10001];
Node node[10001];
int postOrder(int idx, int level ) {
	node[idx].level = level;
	if (mxLevel < level)mxLevel = level;
	if (node[idx].left != -1) node[idx].leftL = postOrder(node[idx].left, level+1);
	if (node[idx].right != -1) node[idx].rightL = postOrder(node[idx].right, level+1);
	return node[idx].leftL + node[idx].rightL + 1; 
}

void setMaxLength(int loc, int level) {
	if (p[level].first == 0) p[level].first = loc;
	else if (p[level].first > loc) p[level].first = loc;
	
	if (p[level].second == 0) p[level].second = loc;
	else if (p[level].second < loc) p[level].second = loc;
}

void setBinaryTree(int idx, int level) {
	if(node[idx].leftL != 0)
		location[idx] = node[idx].leftL + 1;
	else {
		location[idx] = 1;
	}
	setMaxLength(location[idx], level);
	if (node[idx].left != -1) leftTree(node[idx].left, location[idx],  level+1);
	if (node[idx].right != -1) rightTree(node[idx].right, location[idx] , level+1);
}
void rightTree(int idx, int loc, int level) {
	location[idx] = loc + node[idx].leftL + 1;
	setMaxLength(location[idx], level);
	if (node[idx].left != -1) leftTree(node[idx].left, location[idx], level+1);
	if (node[idx].right != -1) rightTree(node[idx].right, location[idx], level+1);
}
void leftTree(int idx, int loc, int level) {
	location[idx] = loc - node[idx].rightL - 1;
	setMaxLength(location[idx], level);
	if (node[idx].left != -1) leftTree(node[idx].left, location[idx], level+1);
	if (node[idx].right != -1) rightTree(node[idx].right, location[idx], level+1);
}

int main() {
	cin >> n;
	int root = 0;
	for (int i = 0; i < n; i++) {
		cin >> v >> x >> y;
		node[v].left = x;
		node[v].right = y;
		if (x != -1) findRoot[x] = true;
		if (y != -1) findRoot[y] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (!findRoot[i]) {
			root = i;
			break;
		}
	}
	postOrder(root, 1);
	setBinaryTree(root, 1);
	for (int i = 1; i <= mxLevel; i++) {
		int temp = p[i].second - p[i].first + 1;
		if (temp > length) {
			length = temp;
			depth = i;
		}
	}
	cout << depth << " " << length << endl;
	return 0;
}
