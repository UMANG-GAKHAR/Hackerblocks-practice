#include <bits/stdc++.h>
using namespace std;

const int N=20;
int a[N][N],dp[N][N],b[N][N];

void fill(int x,int n)
{

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 5; j++)
            b[i][j] = a[i][j];
    }
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            dp[i][j] = -1e8;

    for(int i = x ; i < x+5 ; i++){
        for(int j = 0 ; j < 5 ; j++)
            if(b[i][j] == -1) b[i][j] = 0 ;
    }

}

int hello(int i, int j)
{
     if(i==-1) return 0;

     if(dp[i][j]!=-1e8) return dp[i][j];
     int &ans=dp[i][j];

     ans=max(ans,b[i][j]+hello(i-1,j));
     if(j>0) 
          ans=max(ans,b[i][j]+hello(i-1,j-1));
     if(j<4)
          ans=max(ans,b[i][j]+hello(i-1,j+1));

     return ans;
}

void solve()
{
     int n,m,k;
     cin>>n;
    for(int i = 0 ;  i < n ; i++) 
        for(int j = 0 ; j < 5 ; j++)    
            cin >> a[i][j];


     int ans=-1e8;
     for(int i = 0 ; i < n - 4 ; i++)
     {
          fill(i,n);
          ans=max(ans,hello(n,2));
     }
     cout<<ans<<endl;
}

int32_t main()
{
    
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
