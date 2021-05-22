#include <bits/stdc++.h>
using namespace std;
#define boost  ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define f(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define ms(a,b) memset((a),(b),sizeof(a))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
#define abs(x) ((x<0)?(-(x)):(x))
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN
//typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}

/*..................................................................................................................................*/
char s[MAX];
int previous_count[200],hash[200];
ll dp[MAX],sum[MAX];
int main() 
{
    boost;cin.tie(0);cout.tie(0);
   // freopen("input4.txt","r",stdin);
    int n,t;cin>>t;
    while(t--)
    {
        cin>>s;
        ms(previous_count,-1);
        n=strlen(s);
        ms(dp,0);
        dp[0]=1;
        previous_count[s[0]]=0;
        f(i,1,n)
        {
          dp[i]=(2*dp[i-1])%mod;
          if(previous_count[s[i-1]]!=-1)
            dp[i]=(dp[i]-dp[previous_count[s[i-1]]-1]+mod)%mod;
        previous_count[s[i-1]]=i;
        }
       // freopen("output4.txt","a",stdout);
        cout<<dp[n]<<endl;
    }
   return 0;
}
