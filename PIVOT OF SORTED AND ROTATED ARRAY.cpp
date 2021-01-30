#include<iostream>
using namespace std;
int* getArray(int n){
    int *arr = new int[n];
    for(int i = 0; i < n;++i){
        cin>>arr[i];
    }
    return arr;
}
int findPivot(int *arr,int low,int high){
    if(low>high){
        return -1;
    }
    else
    if(low==high){
        return low;
    }
    int mid = (low + high)/2;
    if(mid < high && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(mid > low && arr[mid] < arr[mid-1]){
        return mid-1;
    }
    if(arr[low] >= arr[mid]){
        return findPivot(arr,low,mid-1);
    }
    return findPivot(arr,mid+1,high);
}
int main() {
    int n;
    cin>>n;
    int *arr = getArray(n);
    int pivot = findPivot(arr,0,n-1);
    cout<<pivot<<endl;
    return 0;
}
