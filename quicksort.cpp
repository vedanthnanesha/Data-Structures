#include <bits/stdc++.h>
using namespace std;

int partition(char arr[], int low, int high){
    char pivot = arr[high];
    int i = low-1;
    int j;
    for(j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(char arr[], int low, int high){
    if(high<=low){
        return;
    }
    int element = partition(arr,low,high);


    quicksort(arr,low,element-1);
    quicksort(arr,element+1,high);
}

int main(){

    char arr[]= {'D','M','W','F','T','A','R','P','K','X','U','Q','H','C','E','I','V','S','N','G','L','Z','B','J','O','Y'};
    cout<<"Before sorting, the array is : ";
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,n-1);

    cout<<"After sorting, the array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
