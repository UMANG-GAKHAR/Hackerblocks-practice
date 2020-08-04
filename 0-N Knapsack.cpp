#include <iostream>
using namespace std;
int main() 
{

    int n,w;
    cin>>n>>w;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    int dp[n+1][w+1]={};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);

            if(arr[i-1]<=j)
            {
                dp[i][j] = max(dp[i][j],dp[i][j-arr[i-1]]+brr[i-1]);
            }
        }
    }
    cout<<dp[n][w];
}
