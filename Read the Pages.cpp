#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
#define ll long long
bool canRead(int *a, int n, int m, int curr){
	long long int pages=0;
	int count=1;
	for(int i=0;i<n;i++){
		if(pages + a[i] > curr){
			pages = a[i];
			count++;
			if(count>m){
				return false;
			}
		}else{
			pages += a[i];
		}
	}
	return true;
}
int find(int a[], int n, int m, ll sum){
	long long int ans = INT_MAX;
	long long int s = a[n-1];
	long long int e =sum;
	while(s<=e){
		long long int mid = (s+e)/2;
		if(canRead(a,n,m,mid)){
			ans = min(ans, mid);
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	return ans;
}
int main () {
	int n,m;	cin>>n>>m;
	ll sum=0;
	int a[100005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	cout<<find(a,n,m,sum);
	return 0;
}
