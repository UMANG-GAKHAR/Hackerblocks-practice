#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test(t) ll t; cin>>t; while(t--)
bool generate_subsequence(ll *a,ll *b,ll n, ll i,ll j)
{
    //base case;
    if(i==n)
    {
        ll sum=0;
        if(j!=0)
        {
            for(ll l=0;l<j;l++)
                sum=sum+b[l];
            if(sum==0)      // check for sum only when j!=0
                return true;   
        }
        return false;
    }
    //considering current element
    b[j]=a[i];
    if(generate_subsequence(a,b,n,i+1,j+1))   //if answer found return true
        return true;
    // not considering the element
    if(generate_subsequence(a,b,n,i+1,j))   //same here
        return true;   
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test(t)
    {
        ll n,i;
        cin>>n;
        ll a[n],b[n];

        for(i=0;i<n;i++)
            cin>>a[i];
        ll ans=generate_subsequence(a,b,n,0,0);   
        if(ans==1)
         cout<<"Yes"<<endl;
        else 
        cout<<"No"<<endl;
    }
    return 0;
}
