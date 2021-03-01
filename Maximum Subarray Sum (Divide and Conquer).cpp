#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll merge(ll * a,int s,int e)
{
	ll sum=0;
    ll max=a[s];
    if(a[s]<0)
        max=0;
	for(int i=s;i<=e;i++)
    {
        sum+=a[i];
        if(max<=sum)
        {
            max=sum;
        }
        
        if(sum<0)
            sum=0;
    }
    return max;

}
ll merging(ll *arr,int s,int e)
{
	if(s==e){ return arr[s]; }
	if(s>e){ return -100000000000000; }
	int m=(s+e)/2;
	ll x=merging(arr,s,m);
	ll y=merging(arr,m+1,e);
	ll z=merge(arr,s,e);
	return max(x,max(y,z));
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll arr[100000];
        int flag=0;
		for(int i=0;i<n;i++)
        {
			cin>>arr[i];
            if(arr[i]>=0)
                flag=1;
        }
        if(flag)
		    cout<<merging(arr,0,n-1)<<endl;
        else{
            ll max=INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(arr[i]>max)
                    max=arr[i];

            }
            cout<<max<<endl;
        }
	}
	return 0;
}
