#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[110],dp[110][110],temp,k,l,sum[110][110];
int main(){
//    freopen("input5.txt","r",stdin);
//    freopen("output5.txt","w",stdout);
//    ios::sync_wth_stdio(0);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++){
        sum[i][i]=temp = a[i];
        for(j=i+1;j<n;j++){
            temp += a[j];
            sum[i][j] = temp%100;
        }
    }
    for(i=0;i<n;i++)
        dp[i][i] = 0;
    for(j=1;j<n;j++){
        for(i=0;i<n-j;i++){
            dp[i][i+j] = INT_MAX;
            for(k=i;k<i+j;k++){
                dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+sum[i][k]*sum[k+1][i+j]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}
