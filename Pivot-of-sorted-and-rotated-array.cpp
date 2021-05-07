#include<iostream>
using namespace std;
int findPivot(int a[],int s,int e){
    if(s>e){
        return -1;
    }
    while(s<=e){
        int mid = (s+e)/2;

        ///Current Element is Mid
        if(mid<e&&a[mid]>a[mid+1]){
            return mid;
        }
        ///Prev of current element is mid
        if(mid>s&&a[mid]<a[mid-1]){
            return mid-1;
        }
        if(a[s]>=a[mid]){
            e = mid-1;
        }
        else{
            s = mid + 1;
        }

    }

    return -1;
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout << findPivot(a,0 , n-1);
	return 0;
}
