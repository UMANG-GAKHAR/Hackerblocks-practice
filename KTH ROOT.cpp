#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll power(ll mid,ll k ){
	ll ans=1;
	while(k>0){
       if(k&1==1){
		   ans=ans*mid;
		   
	   }
	   mid=mid*mid;
	   k=k>>1;
	}
	return ans;
}
bool greatestInt(ll n,ll k,ll mid){
	if(pow(mid,k)<=n){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	int t;
	cin>>t;
  while(t--){
   ll n;
   ll k;
   cin>>n>>k;
   ll s=1;
   ll e=n;
   ll x;
   while(s<=e){
	   ll mid=(s+e)/2;
	   if(greatestInt(n,k,mid)){
		   x=mid;
		   s=mid+1;
	   }
	   else{
		   e=mid-1;
	   }
   
   }
   cout<<x<<endl;
  }
	return 0;
}
