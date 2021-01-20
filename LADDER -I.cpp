#include<bits/stdc++.h>
using namespace std;

int dp[100001];

const int mod = 1e9+7;

int MOD(int a){
    return (a-((a/mod)*mod));
}

int NumberOfWays(vector<int> &cells,int pos,int k){
    if(pos>=cells.size() || cells[pos]){
        return 0;
    }
    if(pos==cells.size()-1){
        return 1;
    }
    int &res=dp[pos];
    if(res!=-1){
        return res;
    }
    res=0;
    for(int next_cell=pos+1;next_cell-pos<=k;next_cell++){
        if(next_cell>cells.size())break;
        res+=(NumberOfWays(cells,next_cell,k));
        res=MOD(res);
    }
    return res;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> cells(n);
    for(int i=0;i<n;i++){
        cin>>cells[i];
    }

    memset(dp,-1,sizeof dp);

    cout<<NumberOfWays(cells,0,k)<<endl;

}
