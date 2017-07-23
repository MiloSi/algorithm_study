#include <iostream>

using namespace std;
int n, m;
int map[21][21];

/*
y는 세로가 아니고 가로다 -_-;;
x는 가로가 아니고 세로다 -_-;;

편입견이 만들어낸 실수..
*/


inline void swap(int &a, int &b, int& c, int& d) {
	int temp = d;
	d = c;
	c = b;
	b = a;
	a = temp;
}

struct Dice {
	int top;
	int bottom;
	int front;
	int rear;
	int right;
	int left;
};

void check(int x, int y, Dice& d) {
	if (map[x][y] == 0)
		map[x][y] = d.bottom;
	else {
		d.bottom = map[x][y];
		map[x][y] = 0;
	}
	cout << d.top << endl;
}


void north(int &x, int &y, Dice& d) {
	
	if(x == 0) {
		return;
	}
	swap(d.top, d.rear, d.bottom, d.front);

	x--;
	check(x, y, d);

}
void south(int &x, int &y, Dice& d) {
	if (x == n - 1) {
		
		return;
	}

	swap(d.top, d.front, d.bottom, d.rear);

	x++;
	check(x, y, d);
}

void west(int &x, int &y, Dice& d) {
	if (y == 0) {
		
		return;
	}
	swap(d.top, d.left, d.bottom, d.right);

	y--;
	check(x, y, d);
}

void east(int &x, int &y, Dice& d) {
	if (y == m - 1) {
		return;
	}
	swap(d.top, d.right, d.bottom, d.left);
	
	y++;
	check(x, y, d);
}

int main() {

	int x, y, k;
	int order;

	Dice d = { 0, 0, 0, 0, 0, 0 };
	cin >> n >> m >> x >> y >>k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> order;

		switch (order)
		{
		case 1 :
			east(x,y,d);
			break;
		case 2:
			west(x, y, d);
			break;
		case 3:
			north(x, y, d);
			break;
		case 4:
			south(x, y, d);
			break;
		}
	}

	return 0;

}