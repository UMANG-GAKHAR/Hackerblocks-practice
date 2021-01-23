#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin>>n;
    ll cnt[100001] = {0};
    ll sum[100001] = {0};
    ll inp;
    for(ll i=0;i<n;i++){
        cin>>inp;
        cnt[inp]++;
    }
    sum[0] = 0; 
    sum[1] = n;
    for(ll i=2;i<100001;i++){
        for(ll j=i;j<100001;j+=i){
            sum[i] += cnt[j];
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll k; 
        cin>>k;
        cout<<sum[k]<<endl;
    }
    return 0;
}
