#include<iostream>
using namespace std;
void input(int arr[],int n){
    if(n==0){return;}
    input(arr,n-1);
    cin>>arr[n-1];
}
void bubblesort(int arr[],int n){
    if(n==1){return;}
    bubblesort(arr,n-1);
    if(arr[n-1]<arr[n-2]){
        int tmp=arr[n-1];
        arr[n-1]=arr[n-2];
        arr[n-2]=tmp;
        bubblesort(arr,n-1);
    }
}
void output(int arr[],int n){
    if(n==0)return;
    output(arr,n-1);
    cout<<arr[n-1]<<" ";
}
int main() {
    int arr[100],n;
    cin>>n;
    input(arr,n);
    bubblesort(arr,n);
    output(arr,n);
    return 0;
}
