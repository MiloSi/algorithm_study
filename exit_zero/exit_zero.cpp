//#include <iostream>
//#include <utility>
//#include <queue>
//using namespace std;
//char board[11][11];
//
//int result = -1;
//
//
//typedef struct _NODE{
//	pair<int, int> r;
//	pair<int, int> b;
//	int w;
//}node;
//queue<node> q;
//pair<int, int> red, blue;
//
//void gameStart() {
//	node t = { red, blue, 0 };
//	q.push(t);
//
//	while (q.size()) {
//		node n = q.front();
//		q.pop();
//		pair<int, int> r = n.r;
//		pair<int, int> b = n.b;
//		int w = n.w;
//
//
//		if (w == 10) break;
//
//		//¿ÞÂÊ
//		{
//			pair<int, int> r1;
//			pair<int, int> b1;
//			int temp1 = r.second - 1;
//			int temp2 = b.second - 1;
//			if (r.second < b.second) {
//				while (board[r.first][temp1] == '.') temp1--;
//				if (board[r.first][temp1] != 'O') {
//					temp1++;
//				}
//				else {
//					temp1 = -1;
//				}
//
//				if(r.first == b.first) while (board[b.first][temp2] == '.' && temp1 != temp2) temp2--;
//				else while (board[b.first][temp2] == '.') temp2--;
//				if (board[b.first][temp2] != 'O') {
//
//					if (temp1 == -1) {
//						result = w + 1;
//						break;
//					}
//
//					temp2++;
//					r1 = { r.first, temp1 };
//					b1 = { b.first, temp2 };
//					node n1 = { r1, b1, w + 1 };
//					q.push(n1);
//				}
//			}
//			else {
//				while (board[b.first][temp2] == '.') temp2--;
//				if (board[b.first][temp2] != 'O') {
//					temp2++;
//					if (r.first == b.first) while (board[r.first][temp1] == '.' && temp1 != temp2) temp1--;
//					else while (board[r.first][temp1] == '.') temp1--;
//
//					if (board[r.first][temp1] != 'O') {
//						temp1++;
//						r1 = { r.first, temp1 };
//						b1 = { b.first, temp2 };
//						node n1 = { r1, b1, w + 1 };
//						q.push(n1);
//					}
//					else {
//						result = w + 1;
//						break;
//					}
//				}
//			}
//		}
//
//
//
//
//		{ // ¿À¸¥ÂÊ
//			pair<int, int> r1;
//			pair<int, int> b1;
//			int temp1 = r.second + 1;
//			int temp2 = b.second + 1;
//			if (r.second > b.second) {
//				while (board[r.first][temp1] == '.') temp1++;
//				if (board[r.first][temp1] != 'O') {
//					temp1--;
//				}
//				else {
//					temp1 = -1;
//				}
//
//				if (r.first == b.first) while (board[b.first][temp2] == '.' && temp1 != temp2) temp2++;
//				else while (board[b.first][temp2] == '.') temp2++;
//				if (board[b.first][temp2] != 'O') {
//
//					if (temp1 == -1) {
//						result = w + 1;
//						break;
//					}
//
//					temp2--;
//					r1 = { r.first, temp1 };
//					b1 = { b.first, temp2 };
//					node n1 = { r1, b1, w + 1 };
//					q.push(n1);
//				}
//			}
//			else {
//				while (board[b.first][temp2] == '.') temp2++;
//				if (board[b.first][temp2] != 'O') {
//					temp2--;
//					if (r.first == b.first) while (board[r.first][temp1] == '.' && temp1 != temp2) temp1++;
//					else while (board[r.first][temp1] == '.') temp1++;
//
//					if (board[r.first][temp1] != 'O') {
//						temp1--;
//						r1 = { r.first, temp1 };
//						b1 = { b.first, temp2 };
//						node n1 = { r1, b1, w + 1 };
//						q.push(n1);
//					}
//					else {
//						result = w + 1;
//						break;
//					}
//				}
//			}
//		}
//
//		//ºÏ
//		{
//			pair<int, int> r1;
//			pair<int, int> b1;
//			int temp1 = r.first - 1;
//			int temp2 = b.first - 1;
//			if (r.first < b.first) {
//				while (board[temp1][r.second] == '.') temp1--;
//				if (board[temp1][r.second] != 'O') {
//					temp1++;
//				}
//				else {
//					temp1 = -1;
//				}
//
//				if (r.second == b.second) while (board[temp2][b.second] == '.'  && temp1 != temp2) temp2--;
//				else while (board[temp2][b.second] == '.') temp2--;
//				if (board[temp2][b.second] != 'O') {
//
//					if (temp1 == -1) {
//						result = w + 1;
//						break;
//					}
//
//					temp2++;
//					r1 = {temp1, r.second};
//					b1 = {temp2, b.second};
//					node n1 = { r1, b1, w + 1 };
//					q.push(n1);
//				}
//			}
//			else {
//				while (board[temp2][b.second] == '.') temp2--;
//				if (board[temp2][b.second] != 'O') {
//					temp2++;
//					if (r.second == b.second) while (board[temp1][r.second] == '.' && temp1 != temp2) temp1--;
//					else while (board[temp1][r.second] == '.') temp1--;
//
//					if (board[temp1][r.second] != 'O') {
//						temp1++;
//						r1 = { temp1, r.second };
//						b1 = { temp2, b.second };
//						node n1 = { r1, b1, w + 1 };
//						q.push(n1);
//					}
//					else {
//						result = w + 1;
//						break;
//					}
//				}
//			}
//		}
//
//		//³²
//		{
//			pair<int, int> r1;
//			pair<int, int> b1;
//			int temp1 = r.first + 1;
//			int temp2 = b.first + 1;
//			if (r.first > b.first) {
//				while (board[temp1][r.second] == '.') temp1++;
//				if (board[temp1][r.second] != 'O') {
//					temp1--;
//				}
//				else {
//					temp1 = -1;
//				}
//
//				if (r.second == b.second) while (board[temp2][b.second] == '.' && temp1 != temp2) temp2++;
//				else while (board[temp2][b.second] == '.') temp2++;
//				if (board[temp2][b.second] != 'O') {
//
//					if (temp1 == -1) {
//						result = w + 1;
//						break;
//					}
//
//					temp2--;
//					r1 = { temp1, r.second };
//					b1 = { temp2, b.second };
//					node n1 = { r1, b1, w + 1 };
//					q.push(n1);
//				}
//			}
//			else {
//				while (board[temp2][b.second] == '.') temp2++;
//				if (board[temp2][b.second] != 'O') {
//					temp2--;
//					if (r.second == b.second) while (board[temp1][r.second] == '.' && temp1 != temp2) temp1++;
//					else while (board[temp1][r.second] == '.') temp1++;
//
//					if (board[temp1][r.second] != 'O') {
//						temp1--;
//						r1 = { temp1, r.second };
//						b1 = { temp2, b.second };
//						node n1 = { r1, b1, w + 1 };
//						q.push(n1);
//					}
//					else {
//						result = w + 1;
//						break;
//					}
//				}
//			}
//		}
//	
//	}
//
//}
//
//
//
//
//
//
//
//
//int main() {
//	int n, m;
//
//
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> board[i][j];
//
//			switch (board[i][j])
//			{
//
//			case 'R':
//				board[i][j] = '.';
//				red = { i, j };
//				break;
//			case 'B':
//				board[i][j] = '.';
//				blue = { i, j };
//				break;
//			}
//		}
//	}
//
//	gameStart();
//
//	cout << result << endl;
//
//	return 0;
//}
//
//
//
