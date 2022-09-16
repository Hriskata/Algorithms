#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// time = O(nlogn), space O(n)
void Merge(unsigned int arr[], unsigned int const left, unsigned int const mid, unsigned int rigth)
{
    // number of elements
    // left <-> mid(including) 
    unsigned int subArrayLeft = mid - left + 1;
    // mid + 1 <-> rigth
    unsigned int subArrayRigth = rigth - mid;

    // creating temp arrays
    unsigned int* leftArray = new unsigned int[subArrayLeft];
    unsigned int* rigthArray = new unsigned int[subArrayRigth];

    // copy data to temp arrays
    for (size_t i = 0; i < subArrayLeft; i++)
        leftArray[i] = arr[left + i];
    for (size_t i = 0; i < subArrayRigth; i++)
        rigthArray[i] = arr[mid + 1 + i];

    // Initial indexs
    unsigned int indexOfSubArrLeft = 0;
    unsigned int indexOfSubArrRigth = 0;
    unsigned int indexOfMergedArr = left;

    // Merge the temp arrays back into array
    while (indexOfSubArrLeft < subArrayLeft && indexOfSubArrRigth < subArrayRigth)
    {
        if (leftArray[indexOfSubArrLeft] <= rigthArray[indexOfSubArrRigth])
        {
            arr[indexOfMergedArr] = leftArray[indexOfSubArrLeft];
            indexOfSubArrLeft++;
        }
        else
        {
            arr[indexOfMergedArr] = rigthArray[indexOfSubArrRigth];
            indexOfSubArrRigth++;
        }
        indexOfMergedArr++;
    }

    // Copy the remainng elements of leftArray 
    while (indexOfSubArrLeft < subArrayLeft)
    {
        arr[indexOfMergedArr] = leftArray[indexOfSubArrLeft];
        indexOfMergedArr++;
        indexOfSubArrLeft++;
    }

    // Copy the remainng elements of rigthArray 
    while (indexOfSubArrRigth < subArrayRigth)
    {
        arr[indexOfMergedArr] = rigthArray[indexOfSubArrRigth];
        indexOfMergedArr++;
        indexOfSubArrRigth++;
    }

    delete[] leftArray;
    delete[] rigthArray;
}

void MergeSort(unsigned int arr[],int const begin, int const end)
{
    if (begin >= end)
        return;

    unsigned int mid = begin + (end - begin)/2 ;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr, begin, mid, end);
}

int main() {
    // number of elements
    unsigned int N;
    cin >> N;

    // array of numbers
    unsigned int* arr = new unsigned int[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr,0,N-1);

    // Print
    for (size_t i = N-1; i > 0; i--)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
