#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test(t) ll t; cin>>t; while(t--)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    ll n,a,i,cnt=0,ans=0,sum=0;
    cin>>n;
    unordered_map<ll,ll>m;
    vector<ll>v(n);
    for(i=0;i<n;i++)
    cin>>v[i];

    ll j=0;
    for(i=0;i<n;i++)
    {
        while(j<n and m.find(v[j])==m.end())
        {
            cnt++;
            m[v[j]]=j;
            j++;
        }

        ans+=(j-i)*(j-i+1)/2;
       
    }
    cout<<ans%MOD;
    return 0;
}
