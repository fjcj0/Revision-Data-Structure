#include<iostream>
#include<algorithm>
using namespace std;
void bubbleSort(int arr[], int n)
{
    bool flag = true;
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
            c++;
        }
        if (flag == true)
            break;
    }
    cout << "number of rounds:" << c << endl;
}
void printArray(int arr[], int n)
{
    cout << "Bubble Sort: [";
    for (int i = 0; i < n; i++){
        cout << arr[i];
        if(i<n-1) cout << ",";
    }
    cout << "]"<<endl;
}
int main()
{
    int arr[] = { 30,20,40,5,60,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
