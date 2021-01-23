#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll power(ll a,ll b,ll md = mod) 
{
    ll product = 1; 
    while(b)
    {
        if(b&1)
        {
            product = (product*a)%md;
        }
        a = (a*a)%md;
        b = b>>1;
    } 
    return product%md;
}
ll sum(ll n)
{
    return ((n*(n+1))/2)%mod;
}
int main()
{       
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll pro = 1;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
        pro = (pro*(v[i]+1))%mod;
    }
    ll ans = 1;

    for(int i = 0; i < n; i++)
    {
        ans = (ans*(1+((sum(v[i])*((pro*power(v[i]+1,mod-2))%mod))%mod)))%mod;
    }

    cout<<ans<<endl;


    return 0;
}   
