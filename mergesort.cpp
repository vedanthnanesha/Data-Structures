#include <iostream>
#include <vector>
using namespace std;

void merge(int array[], int start, int end)
{
    int i = start;
    int m = (start + end) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m && j <= end)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }


    while (i <= m)
    {
        temp.push_back(array[i++]);
    }


    while (j <= end)
    {
        temp.push_back(array[j++]);
    }

    int k = 0;
    for (int elem = start; elem <= end; elem++)
    {
        array[elem] = temp[k++];
    }
    return;
}

void mergesort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    return merge(arr, start, end);
}

int main()
{

    int arr[]= {16,11,13,4,1,6,7,21};
    int start = 0;
    int end = 7;
    mergesort(arr, start, end);
    for (int i = 0; i < end; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
