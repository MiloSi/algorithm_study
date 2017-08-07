#include <iostream>
using namespace std;
int arr[301][301];

int n, k;
#define LOP(i,j,k) for(int i = j; i <= k; i++)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int y, x;
	cin >> n >> k;
	LOP(i, 1, k) {
		cin >> y >> x;
		arr[y][x] = 1;
		arr[x][y] = -1;
	}
	//알고리즘 작성
	LOP(i, 1, n) {
		LOP(j, 1, n) {
			LOP(l, 1, n) {
				if (arr[j][l] == 0) {
					if (arr[j][i] == arr[i][l]) arr[i][l] = arr[j][i];
				}
			}
		}
	}
	int m;
	cin >> m;
	LOP(i, 1, m) {
		cin >> y >> x;
		cout << arr[y][x] << endl;
	}
	return 0;
}