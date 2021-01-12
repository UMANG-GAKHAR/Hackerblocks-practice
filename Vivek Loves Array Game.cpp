#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pre;
map<pair<int,int>,int> my;
int maxScore(vector<int> &a,int l,int r){
    if(l==r)return 0LL;
    if(l>r)return 0LL;
    int totalSum=pre[r]-(l?pre[l-1]:0);
    int ind;
    if(totalSum%2)return 0LL;
    int sum=0;
    bool flag=false;
    for(int j=l;j<=r;j++){
        sum+=a[j];
        if(sum==(totalSum/2)){
            ind=j;
            flag=true;
            break;
        }
    }
    if(!flag)return 0;

    return 1+max(maxScore(a,l,ind),maxScore(a,ind+1,r));
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);cout.tie(0);
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        pre.clear();
        pre.resize(n);
        my.clear();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(i==0)pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }

        printf("%lld\n",maxScore(a,0,n-1));
    }
    return 0;
}
