#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LIMIT 1000005
ll p[1000005]={0};
ll tot[1000005]={0};
void prime_sieve(){
    for(ll i=3;i<LIMIT;i+=2)p[i]=1;
    for(ll i=3;i<LIMIT;i+=2){
        if(p[i]){
        for(ll j=i*i;j<LIMIT;j+=(2*i)){
            p[j]=0;
        }
    }

}
p[2]=1;
return;
}
void x(){
    for(ll i=0;i<LIMIT;i++)tot[i]=i;
    for(ll i=2;i<LIMIT;i++){
        if(p[i]){
            for(ll j=i;j<LIMIT;j+=i){
                tot[j]*=(i-1);
                tot[j]/=i;

            }
        }
    }
    return;
}
int main(){
    ll t;
    prime_sieve();
    x();
    cin>>t;
    ll num1;
	//tot[1]=0;
    while(t--){
        cin>>num1;
        
        cout<<tot[num1]<<endl;
    }
    return 0;
}
