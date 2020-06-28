#include <iostream>
using namespace std;
int SmallInd(int arr[],int beg,int end) {
    if(beg==end){
        return beg;
    }
    else{
        int x=SmallInd(arr,beg,end-1);
        if(arr[end]<arr[x]){
            x=end;
        }
        return x;
    }
}
void SwapElements(int arr[],int x,int y){
    int tmp=arr[x];
    arr[x]=arr[y];
    arr[y]=tmp;
}
void InputArray(int arr[],int n){
    if(n<=0) return ;
    InputArray(arr,n-1);
    cin>>arr[n-1];
}
void SelectionSort(int arr[],int n,int size) {
    if(n<=0){return;}
    SelectionSort(arr,n-1,size);
    SwapElements(arr,n-1,SmallInd(arr,n-1,size-1));
    }
void PrintArray(int arr[],int n){
    if(n<=0){
        return ;
    }
    else{
        PrintArray(arr,n-1);
        cout<<arr[n-1]<<" ";
    }
}
int main() {
    int arr[100],n;
    cin>>n;
    InputArray(arr,n);
    SelectionSort(arr,n,n);
    PrintArray(arr,n);
}
