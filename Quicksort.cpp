#include <iostream>
using namespace std;
int partition(int a[],int s,int e){
    int i=s;
    int j=s;
    int pivot=a[e];
    for(;j<=e-1;j++){
        if(a[j]<=pivot){
            swap(a[i],a[j]);
             i=i+1;
        }
    }
    swap(a[i],a[e]);
    return i;
}

void quickSort(int a[],int s,int e){
    if(s>e){
        return;
    }

    int p=partition(a,s,e);
    //Left Part
    quickSort(a,s,p-1);
    //Right Part
    quickSort(a,p+1,e);
}
int main() {
    int n;
	//int a[n];
    cin>>n;
    int a[n];//Array must be formed after taking n as input
	for(int i=0;i<n;i++)
	cin>>a[i];
    int s=0,e=n-1;
    quickSort(a,s,e);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
