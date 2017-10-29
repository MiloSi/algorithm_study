#pragma warning (disable:4996)
#include <stdio.h>
#include <math.h>
int arr[100][100];
int stack[2][10];
int n, k;

int getRows() {
	int rows = 0, plats;
	bool edges, okay;
	for (int i = 0; i < n; i++) {
		plats = 1;
		edges = false;
		okay = true;
		for (int j = 0; j < n - 1; j++) {
			int diff = arr[i][j + 1] - arr[i][j];
			if (diff == 0) {
				plats++;

				if (edges) {
					if(plats == k)
					{
						edges = 0;
						plats = 0;
					}
				}
			}
			else if (diff == 1) {
				if (plats >= k) {
					plats = 1;
				}
				else {
					okay = false;
					break;
				}
			}
			else if (diff == -1) {
				if (edges) {
					okay = false;
					break;
				}
				edges = true;
				plats = 1;
				if (plats == k) {
					plats = 0;
					edges = false;
				}
			}
			else {
				okay = false;
				break;
			}
		}
		if (edges) okay = false;
		if (okay)
			rows++;
	}
	return rows;
}
int getCols() {
	int cols = 0, plats;
	bool edges, okay;
	for (int j = 0; j < n; j++) {
		plats = 1;
		okay = true;

		edges = false;
		for (int i = 0; i < n-1; i++) {
			int diff = arr[i+1][j] - arr[i][j];
			if (diff == 0) {
				plats++;

				if (edges) {
					if (plats == k)
					{
						edges = 0;
						plats = 0;
					}
				}
			}
			else if (diff == 1) {
				if (plats >= k) {
					plats = 1;
				}
				else {
					okay = false;
					break;
				}
			}
			else if (diff == -1) {
				if (edges) {
					okay = false;
					break;
				}
				edges = true;
				plats = 1;
				if (plats == k) {
					plats = 0;
					edges = false;
				}
			}
			else {
				okay = false;
				break;
			}
		}
		if (edges) okay = false;
		if (okay)
			cols++;
	}
	return cols;
}

int main() {
	scanf("%d%d", &n, &k);

	int rows, cols;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	rows = getRows();
	cols = getCols();
	printf("%d\n", rows + cols);
}
