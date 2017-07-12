#include <iostream>
using namespace std;
#define SIZE 16
#define N SIZE

inline void SWAP(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void insertion_sort(int  *arr)
{
	int temp;
	int j;
	for (int i = 1; i < N; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > temp) arr[j + 1] = arr[j];
			else break;
		}
		arr[j + 1] = temp;
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
	int arr[SIZE] = { 1, 11, 2, 8, 4, 19, 3, 42, 5, 7, 10, 6, 9, 64, 16, 12};

	cout << "INSERTON SORT" << endl;
	show(arr);
	insertion_sort(arr);
	show(arr);

	return 0;
}

