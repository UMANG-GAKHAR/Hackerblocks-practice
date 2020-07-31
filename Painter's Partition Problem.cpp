#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool func(ll *a,ll n,ll k,ll mid){
	ll start = 0;
	ll painter = 1;
	for(ll i=0;i<n;i++){
        if (a[i] > mid) {
            return false;
        }
		if(start+a[i]>mid){
			painter++;
			start = a[i];
			if(painter > k){
				return false;
			}
		}
		else{
			start += a[i];
		}
	}
	return painter <= k;
}

int main() {
	ll p; cin>>p;
	ll b; cin>>b;
	ll a[b];
	ll total=0;
	for(ll i=0;i<b;i++){
		cin>>a[i];
		total+=a[i];
	}
	ll s = 0;
	ll e = total;
	ll ans=total;
	ll mid;
	while(s<=e){
		mid = (s+e)/2;
		bool call = func(a,b,p,mid);
		if(call){
			ans = mid;
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
    cout << ans;
	return 0;
}
