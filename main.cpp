#include<iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n)
{
    cout << "Intersection Sort: [";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if(i<n-1)cout << ",";
    }
    cout << "]" << endl;
}
int main()
{
        int arr[] = { 80 , 90 ,60 ,30 ,50 ,70 ,40 };
        int n = sizeof(arr) / sizeof(arr[0]);//28/4=7
        insertionSort(arr, n);
        printArray(arr, n);
        return 0;
}
