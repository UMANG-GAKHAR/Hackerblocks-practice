#include<iostream>
#include<climits>
using namespace std;
bool cankeep(long long int arr[],int n,int m,long long mid_step)
{
	long long int pages=0;
	long long int students=1,i;
	for(i=0;i<n;i++)
	{
		if(pages+arr[i]>mid_step)
		{
			pages=arr[i];
			students++;
			if(students>m)
			{
				return false;
			}
		}
		else{
			pages+=arr[i];
		}	
	}
	return true;
}
int main() {
	long long arr[100],mid,sum=0,s,e,ans;
	int n,m,i,j,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>m;
		long long mx=INT_MIN;
		sum=0;
		for(j=0;j<n;j++)
		{
			cin>>arr[j];
			sum=sum+arr[j];
			mx=max(mx,arr[j]);
		}
		s=mx;
		e=sum;
		ans=sum;
		while(s<=e)
		{
			mid=(s+e)/2;
			if(cankeep(arr,n,m,mid))
			{
				ans=mid;
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
