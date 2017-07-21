#include <iostream>
using namespace std;

int board[51][51];
int w;
int n, m;


bool check(int &x, int& y, int x1, int y1) {
	if (board[y1][x1] == 0) {
		y = y1;
		x = x1;
		board[y1][x1] = 2;
		w++;
		return true;
	}
	return false;

}


void search(int y, int x, int d) {

	board[y][x] = 2;
	w++;
	int isCheck = 0;

	while (1) {
		d--;
		if (d < 0)
			d = 3;

		isCheck = 0;
		while (isCheck != 4) {
			if (y > 0 && d == 0) {
				if(check(x, y, x, y - 1))
					break;
			}
			else if (y < n - 1 && d == 2) {
				if(check(x, y, x, y + 1))
					break;
			}
			else if (x > 0 && d == 3) {
				if(check(x, y, x - 1, y))
					break;
			}

			else if (x < m - 1 && d == 1) {
				if(check(x, y, x + 1, y))
					break;
			}
			isCheck++;
			d--;
			if (d < 0)
				d = 3;
		}
		if (isCheck == 4)
		{
			d++;
			if (d == 4)
				d = 0;
			if (d == 0)
			{
				if (y == n - 1)
					break;
				else if (board[y + 1][x] == 1)
					break;
				else
					y++;
			}
			else if (d == 1)
			{
				if (x == 0)
					break;
				else if (board[y][x - 1] == 1)
					break;
				else
					x--;
			}
			else if (d == 2)
			{
				if (y == 0)
					break;
				else if (board[y - 1][x] == 1)
					break;
				else
					y--;
			}
			else {
				if (x == m - 1)
					break;
				else if (board[y][x + 1] == 1)
					break;
				else
					x++;
			}
		}
	}


}



int main() {

	int r, c, d;
	w = 0;


	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	search(r, c, d);

	cout << w << endl;

	return 0;
}