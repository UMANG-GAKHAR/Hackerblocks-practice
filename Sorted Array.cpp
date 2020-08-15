#include<iostream>
using namespace std;
 bool isSorted(long long int *a,int n)
 {
	 if(n==0 || n==1)
	 {
		 return true;
	 }
	 if(a[0]<=a[1] && isSorted(a+1,n-1))
	 {
		 return true;
	 }
	 return false;
 }
int main() {
	int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x=isSorted(a,n);
	if(x==1)
	{
		cout<<"true";
	}
	else
	cout<<"false";
	return 0;
}
