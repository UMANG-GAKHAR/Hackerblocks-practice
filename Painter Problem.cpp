/// painter Partition Problem
#include<bits/stdc++.h>
#define mod 10000003
#define ll long long int
using namespace std;

bool canPaint(ll boards[],ll n,ll no_painters, ll mid){
    ll painter=1;
    ll boardPainted=0;
    for(ll i=0;i<n;i++){
        if(boardPainted+boards[i]<=mid){
            boardPainted+=boards[i];
        }
        else{
            painter++;
            if(painter>no_painters)return false;
            boardPainted=boards[i];
        }
    }
    return true;
}

ll PainterPartition(ll boards[],ll n,ll no_painters, ll time){
    ll s=*max_element(boards,boards+n);
    ll e=accumulate(boards,boards+n,e);
    ll ans=INT_MAX;
    while(s<=e){
        ll mid= s+(e-s)/2;
        if(canPaint(boards,n,no_painters,mid)){
            e=mid-1;
            ans=min(ans,mid);
        }
        else{
            s=mid+1;
        }
    }
    return ((ans%mod)*time)%mod;
}

int main(){
    ll boards[100001];
    ll n,no_painters,time;
    cin>>n>>no_painters>>time;
    for(ll i=0;i<n;i++)cin>>boards[i];
    cout<<PainterPartition(boards,n,no_painters, time)<<endl;
    return 0;
}
