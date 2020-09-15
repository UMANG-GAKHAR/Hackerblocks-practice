#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>k;
	string s;
	cin>>s;
	n=s.length();
	int l=0,r=0,cnt =0;
	int mx = 1;
	while(r<n){
		if(s[r]!='a')
			cnt++;
		while(cnt>k){
			if(s[l]!='a') cnt--;
			l++;
		}
		mx= max(r-l+1,mx);
		r++;
	}
	l=0,r=0,cnt=0;
	while(r<n){
		if(s[r]!='b')
			cnt++;
		while(cnt>k){
			if(s[l]!='b') cnt--;
			l++;
		}
		mx= max(r-l+1,mx);
		r++;
	}
	cout<<mx<<endl;
	return 0;
}
