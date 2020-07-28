#include<iostream>
#include<algorithm>
using namespace std;
bool place(int arr[],int n,int c,int mid)
{
	int cnt=1;
	int cow=arr[0];
	for(int i=1;i<n;i++)
	{
		if((arr[i]-cow) >=mid)
		{
			cow=arr[i];
			cnt++;
		
			if(cnt==c)
			{
				return true;
			}
		}	

	}
	if(cnt<c){
return false;}
return true;
}
int main() {
	int n,c,ans;
	cin>>n>>c;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int s=0;
	int e=arr[n-1];
	ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;
		bool c1=place(arr,n,c,mid);
if(c1)
		{
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
