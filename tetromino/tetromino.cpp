#include <iostream>
#include <memory.h>
using namespace std;

int paper[501][501];
int result;

int n, m;

inline int MIN(int a, int b) {
	return a < b ? a : b;
}



inline int sum(int y1, int x1, int y2, int x2) {
	int s = 0;

	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++)
		{
			s += paper[i][j];
		}
	}
	return s;
}


void two_three(int y1, int x1, int y2, int x2) {

	int sub1, sub2, sub3, sub4, sub5, min;
	int s = sum(y1,x1,y2,x2);

	sub1 = MIN(paper[y1][x1] + paper[y1][x1 + 1], paper[y1][x2] + paper[y1][x1 + 1]);
	sub2 = MIN(paper[y2][x1] + paper[y2][x1 + 1], paper[y2][x2] + paper[y2][x1 + 1]);
	sub3 = MIN(paper[y1][x1] + paper[y1][x2], paper[y2][x1] + paper[y2][x2]);
	sub4 = MIN(paper[y1][x1] + paper[y2][x1], paper[y1][x2] + paper[y2][x2]);
	sub5 = MIN(paper[y1][x1] + paper[y2][x2], paper[y1][x2] + paper[y2][x1]);

	sub1 = MIN(sub1, sub2);
	sub3 = MIN(sub3, sub4);
	sub1 = MIN(sub1, sub3);
	min = MIN(sub1, sub5);


	s = s - min;

	if (result < s)
		result = s;

}
void three_two(int y1, int x1, int y2, int x2) {

	int sub1, sub2, sub3, sub4, sub5, min;
	int s = sum(y1, x1, y2, x2);

	sub1 = MIN(paper[y1][x1] + paper[y1+1][x1], paper[y2][x1] + paper[y1+1][x1]);
	sub2 = MIN(paper[y1][x2] + paper[y1 + 1][x2], paper[y2][x2] + paper[y1 + 1][x2]);
	sub3 = MIN(paper[y1][x1] + paper[y1][x2], paper[y2][x1] + paper[y2][x2]);
	sub4 = MIN(paper[y1][x1] + paper[y2][x1], paper[y1][x2] + paper[y2][x2]);
	sub5 = MIN(paper[y1][x1] + paper[y2][x2], paper[y1][x2] + paper[y2][x1]);

	sub1 = MIN(sub1, sub2);
	sub3 = MIN(sub3, sub4);
	sub1 = MIN(sub1, sub3);
	min = MIN(sub1, sub5);


	s = s - min;

	if (result < s)
		result = s;
}
void one_four(int y1, int x1, int y2, int x2) {

	int s = sum(y1, x1, y2, x2);
	if (result < s)
		result = s;
}
void four_one(int y1, int x1, int y2, int x2) {
	int s = sum(y1, x1, y2, x2);
	if (result < s)
		result = s;
}



int main() {
	
	cin >> n >> m;
	result = 0;
	memset(paper, 0, sizeof(paper));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1;j <= m; j++)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i + 1 <= n && j + 2 <= m)
				two_three(i, j, i + 1, j + 2);
			if (i + 2 <= n && j + 1 <= m)
				three_two(i, j, i + 2, j + 1);
			if (j + 3 <= m)
				one_four(i, j, i, j + 3);
			if (i + 3 <= n)
				four_one(i, j, i+3, j);
		}

	}

	cout << result << endl;







	return 0;
}