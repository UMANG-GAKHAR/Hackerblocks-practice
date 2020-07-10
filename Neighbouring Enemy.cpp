#include<bits/stdc++.h>
using namespace std;
#define int long long 


signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> dp((*max_element(a.begin(),a.end()))+1,0);
    for(int i=1;i<dp.size();i++){
        dp[i]=dp[i-1];
        if(1){
            dp[i]=max(dp[i],(i>=2?dp[i-2]:0)+cnt[i]*i);
        }
    }
    cout<<dp[dp.size()-1]<<endl;
    return 0;
}
