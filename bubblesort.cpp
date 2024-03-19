#include <iostream>
#include <ctime>
using namespace std;

void bubblesort(int a[], int n)
{

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            if (a[j]>a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {9,6,7,8,1,3,5,11};
    int n = sizeof(arr) / sizeof(int);

    bubblesort(arr, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
