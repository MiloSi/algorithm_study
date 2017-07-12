#include <iostream>
using namespace std;
#define SIZE 12
#define N SIZE

inline void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection_sort(int  *arr)
{
	int min;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i+1; j < N; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		SWAP(&arr[min], &arr[i]);
	}

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
	int arr[SIZE] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6 };

	cout << "SELECTION SORT" << endl;
	show(arr);
	selection_sort(arr);
	show(arr);

	return 0;
}

