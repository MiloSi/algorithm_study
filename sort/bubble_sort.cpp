#include <iostream>
using namespace std;
#define SIZE 12

inline void SWAP(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int  *arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE -1; j++)
		{
			if (arr[j] > arr[j + 1])
				SWAP(&arr[j], &arr[j + 1]);
		}
	}
}

void show(int *arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[SIZE] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6 };

	
	show(arr);
	bubble_sort(arr);
	show(arr);

	return 0;
}

