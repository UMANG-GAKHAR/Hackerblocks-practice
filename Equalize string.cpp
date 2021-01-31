#include<bits/stdc++.h>
using namespace std;
int EditDistance(string &a,string &b){
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    memset(dp,(int)INT_MAX,sizeof dp);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1]+1;
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
    }
    return dp[n][m];
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<EditDistance(a,b)<<endl;
    return 0;
}
