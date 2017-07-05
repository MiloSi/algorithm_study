
#include <iostream>
#include <memory.h>

using namespace std;

int Answer;
int table[201][201];
int checked[201];

int w;

bool promising(int i);

void coloring(int index, int n) {
	int color;

	if (promising(index)) {
		if (index == n) {
			Answer = 1;
			return;
		}
		else 
			for (color = 1; color <= 2; color++)
			{
				checked[index + 1] = color;
				coloring(index + 1, n);
			}
	}
}
bool promising(int i) {
	int j = 1;
	bool sw = true;
	while (j < i && sw)
	{
		if (table[i][j]) {
			if (checked[i] != 0 && checked[j] != 0 && checked[i] == checked[j]) {
				sw = false;
			}
		}
			
		j++;
	}
	return sw;

}



int main(int argc, char** argv)
{
	int T, test_case;

	int n, m;
	int x, y;
	bool a;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		cin >> n >> m;
		memset(table, 0, sizeof(table));
		memset(checked, 0, sizeof(checked));

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			
			table[y][x] = 1;
			table[x][y] = 1;

		}
		checked[1] = 1;
		coloring(1, n);
	
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}