#include<iostream>
using namespace std;
int Bsearch(int n,int *arr,int key){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[s]<=arr[mid]){
			if(key>=arr[s] && key<=arr[mid]){
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
		else{
			if(key>=arr[mid] && key<=  arr[e]){
				s=mid+1;
			}
			else{
				e=mid-1;
			}
		}
	}
	return -1;
}
int main() {
	int n;
	cin>>n;
	int arr[100000];          
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int key;
	cin>>key;
	cout<<Bsearch(n,arr,key);
}
