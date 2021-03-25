#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define F first
#define S second
#define pb push_back
using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, 
tree_order_statistics_node_update> 
new_data_set; 

const ll N=100005;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;  
        cin>>n;
        ll catalan[n];
        catalan[0]=catalan[1]=1;
        for(i=2;i<=n;i++){
          catalan[i]=0;
          for(j=0;j<i;j++){
            catalan[i]+=catalan[j]*catalan[i-j-1];
          }
        }
        for(i=0;i<=n;i++){
            cout<<i<<" "<<catalan[i]<<'\n';                   
        }
    }
}
