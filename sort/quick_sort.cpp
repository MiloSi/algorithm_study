#include <iostream>
using namespace std;
#define SIZE 16
#define N SIZE

//int arr[N] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6, 9, 64, 16, 12 };


inline void SWAP(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void quick_sort(int* arr, int left, int right)
{
	int l = left;
	int r = right;
	int pivot = arr[left];


	while (left < right)
	{
		while (pivot <= arr[right] && left < right) {
			right--;
		}
		if (left != right) {
			arr[left] = arr[right];
		}

		while (pivot >= arr[left] && left < right) {
			left++;
		}
		if (left != right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = l;
	right = r;
	if (left < pivot) quick_sort(arr, left, pivot-1);	
	if (right > pivot) quick_sort(arr, pivot + 1, right);


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

	cout << "QUICK SORT" << endl;
	show(arr);
	quick_sort(arr, 0, N - 1);
	show(arr);

	return 0;
}

