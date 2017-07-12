#include <iostream>
using namespace std;
#define SIZE 16
#define N SIZE

//int arr[N] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6, 9, 64, 16, 12 };
//int dst[N];

inline void SWAP(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void merge_sort(int left, int right, int *arr, int* dst)
{
	if (left == right) return;
	int m = (left + right) / 2;
	merge_sort(left, m, arr, dst);
	merge_sort(m + 1, right, arr, dst);

	int i = left;
	int lPtr, rPtr;

	lPtr = left;
	rPtr = m+1;

	while (i <= right)
	{
		if (lPtr >= m+1)
		{
			dst[i++] = arr[rPtr++];
		}
		else if (rPtr > right) {
			dst[i++] = arr[lPtr++];
		}
		else if (arr[lPtr] < arr[rPtr])
			dst[i++] = arr[lPtr++];
		else
			dst[i++] = arr[rPtr++];
	}
	for (i = left; i <= right; i++)
		arr[i] = dst[i];

}

void show(int *arr)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[N] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6, 9, 64, 16, 12 };
	int dst[N] = { 0 ,};

	cout << "MERTGE SORT" << endl;
	show(arr);
	merge_sort(0, N-1, arr, dst);
	show(arr);

	return 0;
}

