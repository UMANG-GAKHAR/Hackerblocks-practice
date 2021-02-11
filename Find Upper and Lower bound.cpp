#include<iostream>
using namespace std;
int fstocc(int a[],int n, int key)
{
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(a[mid]==key)
		{
			ans=mid;
			e=mid-1;

		}
		else if(a[mid]<key)
		{
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
return ans;
}
int lstocc(int a[],int n, int key)
{
	int s=0;
	int e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(a[mid]==key)
		{
			ans=mid;
			s=mid+1;

		}
		else if(a[mid]<key)
		{
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
return ans;
}
int main() {
	int n;
	cin>>n;
    int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int no;
	cin>>no;
	for(int i=0; i<no; i++)
	{
	int key;
	cin>>key;
	cout<<fstocc(a,n,key)<<" ";
	cout<<lstocc(a,n,key)<<endl;
	}
	return 0;
}
