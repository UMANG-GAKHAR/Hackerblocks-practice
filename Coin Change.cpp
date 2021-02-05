#include<bits/stdc++.h>
using namespace std;
int dp[100][500];
int NumberOfWays(vector<int> &coins,int N,int pos){
    int &res=dp[pos][N];
    if(res!=-1){
        return res;
    }
    if(N==0){
        return 1;
    }
    if(pos==coins.size()){
        if(N)return 0;
        else return 1;
    }
    res=0;
    res=NumberOfWays(coins,N,pos+1);
    if(N>=coins[pos])
        res+=NumberOfWays(coins,N-coins[pos],pos);
    return res; 
}
signed main(){    
    int n,m;
    cin>>n>>m;
    vector<int> coins(m);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<NumberOfWays(coins,n,0)<<endl;
    return 0;
}
