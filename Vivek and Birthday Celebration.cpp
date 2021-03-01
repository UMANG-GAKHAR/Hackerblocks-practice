#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
vector<ll> v[1000000];
bool visited[1000000];
ll cnt=0;
void dfs(ll a){
visited[a]=true;
cnt++;
for(ll i=0;i<v[a].size();i++){
    if(!visited[v[a][i]])dfs(v[a][i]);
}
}
int main(){
ll n,m;
cin>>n>>m;
ll inco[n],outgo[n];
f(i,0,n){
    inco[i]=0;
    outgo[i]=0;
    visited[i]=0;
}
f(i,0,m){
    ll x,y;
    cin>>x>>y;x--;y--;
    v[x].push_back(y);
     inco[y]++;
     outgo[x]++;
}
vector<ll>v1;
f(i,0,n){
if(!visited[i]){dfs(i);
v1.push_back(cnt);
cnt=0;}
}
sort(v1.begin(),v1.end());
cout<<v1[0]<<endl;
}
