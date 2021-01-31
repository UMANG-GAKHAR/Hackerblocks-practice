#include<bits/stdc++.h>
using namespace std;
int maxSquare(vector<vector<int>> &a){
    int n=a.size(),m=a[0].size();
    int dp[n][m];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                dp[i][j]=0;
                continue;
            }
            if(i==0 || j==0){
                dp[i][j]=1;
                ans=max(ans,dp[i][j]);
                continue;
            }
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<maxSquare(a)<<endl;
    return 0;
}
