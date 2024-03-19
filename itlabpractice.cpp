#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int end){
    int i = start;
    int m= (start+end)/2;
    int j = m +1;

    vector<int> temp;

    while(i<=m && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=m){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    int k = 0;
    for(int elem = start; elem<=end;elem++){
        arr[elem]=temp[k];
        k++;
    }


}

void mergesort(vector <int> &arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid= (start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    return merge(arr,start,end);
}

int main(){
    vector<int> arr{24,78,91,3,4,1,5,99,0};
    mergesort(arr,0,8);
    for(int i=0;i<=8;i++){
        cout<<arr[i]<<" ";
    }
}
