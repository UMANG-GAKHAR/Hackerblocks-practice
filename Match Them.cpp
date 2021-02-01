#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
ll BIT[200005];
void update(ll id,ll val) {
    for(ll i=id;i<=200000;i+=i&-i) BIT[i]+=val;
}
ll query(ll id) {
    ll sum=0;
    for(ll i=id;i>0;i-=i&-i) sum+=BIT[i];
    return sum;
}
ll cnt[100005][10],hass[10],ans;
int main() 
{
    std::ios::sync_with_stdio(false);
    memset(hass,0,sizeof(hass));
    memset(cnt,0,sizeof(cnt));
    ans = 0;
    string x;
    cin>>x;
    ll n = x.length();
    ll m;
    cin>>m;
    F(i,0,m-1)
    {
        ll y;
        cin>>y;
        hass[y]++;
    }
    F(i,0,n-1)
    {
        cnt[i][x[i]-'0']++;
        if(i>=1)
        {
            F(j,0,9)
                cnt[i][j] += cnt[i-1][j];
        }
    }
    /*F(i,0,n-1)
    {
        F(j,0,9)
            cout<<cnt[i][j]<<" ";
        cout<<endl;
    }*/
    F(i,0,n-1)
    {
        ll lo=i,hi=n-1,id=-1;
        while(lo <= hi)
        {
            ll mid = (lo+hi)/2;
            bool check = 1;
            F(j,0,9)
            {
                //debug(hass[j]);
                if(i>=1)
                {
                    //debug(mid);
                    //cout<<cnt[mid][j]-cnt[i-1][j]<<endl;
                    if(hass[j] > cnt[mid][j]-cnt[i-1][j])
                        check = 0;
                }
                else
                {
                    if(hass[j] > cnt[mid][j])
                        check = 0;
                }
            }
            if(check)
            {
                id = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        //debug(id);
        if(id!=-1)
        {
            ans += (n-id);
        }
    }
    cout<<ans<<endl;
    return 0;
}
