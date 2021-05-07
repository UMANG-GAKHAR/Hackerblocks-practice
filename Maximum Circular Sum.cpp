#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,t;
	cin>>t;int sum=0;
	while(t--){
		cin>>n;int arr[n];sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];sum+=arr[i];
		}
		sum=-sum;
		for(int i=0;i<n;i++)
		{
			arr[i]=-arr[i];
		}
		int csum=arr[0],maxs=arr[0];
		for(int i=0;i<n;i++)
		{
			csum+=arr[i];
			if(csum<0){
				csum=0;
			}
			maxs=max(csum,maxs);
		}
		cout<<(-(sum-maxs))<<"\n";
	}
	return 0;
}
