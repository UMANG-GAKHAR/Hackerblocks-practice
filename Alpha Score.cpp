#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll mergeInterval(ll *arr,ll s,ll mid,ll e)
{
    ll n1=mid-s+1;
    ll n2=e-mid;
    ll l[n1];
    ll r[n2];
    for(ll i=0;i<n1;i++)
        l[i]=arr[s+i];
    for(ll i=0;i<n2;i++)
        r[i]=arr[mid+i+1];
    ll i=0,j=0,k=s;
    ll cnt=0;
    while(i<n1 && j<n2)
    {        
        if(l[i]<=r[j])
        {
            
            cnt+=(l[i]*(e-(mid+j))%mod);
            arr[k]=l[i];
            i++;
        }
        else
        {            
            arr[k]=r[j];
            j++;
        }
        k++;        
    }
    while(i<n1)
    {
        arr[k]=l[i];i++;k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];j++;k++;
    }
    return cnt%mod;
}
ll countInversions(ll *arr,ll s,ll e)
{
    if(s>=e)
        return 0;
    ll mid=s+(e-s)/2;
    ll left=countInversions(arr,s,mid);
    ll right=countInversions(arr,mid+1,e);
    ll center= mergeInterval(arr,s,mid,e);
      
    return (left+right+center)%mod;
}
int main()
{
  
        ll n;cin>>n;
        ll *arr=new ll[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];             
        
        cout<<countInversions(arr,0,n-1)<<endl;

}
