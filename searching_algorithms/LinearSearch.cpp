#include <iostream>
using namespace std;


int linearSearch(const int* arr, int len, int searched)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == searched)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << linearSearch(arr, size, 10);
}
