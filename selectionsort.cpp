#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{

    for (int pos = 0; pos <= n - 2; pos++)
    {


        int min_position = pos;

        for (int j = pos+1; j <= n-1; j++)
        {

            if (a[j] < a[min_position])
            {
                min_position = j;
            }
        }

        swap(a[min_position], a[pos]);
    }
}

int main()
{
    int arr[] = {16,11,13,4,1,6,7,21};
    int n = sizeof(arr) / sizeof(int);
    selection_sort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
