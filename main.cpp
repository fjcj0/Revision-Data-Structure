#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(int arr[], int n)
{
    int minIdx;
    for (int i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[minIdx])
                minIdx = j;
                swap(arr[minIdx], arr[i]);
    }
}
void print(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if(i<size-1) cout << ",";
    }
    cout << "]\n";
}
int main()
{
    int arr[] = { -60, 0, 50, 30, 10,20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout<<"Array After Selection Sort: ";
    print(arr, n);
    return 0;
}
