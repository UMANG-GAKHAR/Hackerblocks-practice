#include<iostream>
#include<deque>
using namespace std;
int main(){
	long n;
	cin>>n;
	long *a = new long[n];
	for(long i=0;i<n;i++){
		cin>>a[i];
	}
	long k;
	cin>>k;
	
	deque<long> q(k);
	
	for(long i=0;i<k;i++){
		while(!q.empty() && a[q.back()] <= a[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	for(long i=k;i<n;i++){
        cout<<a[q.front()]<<" ";
		while(!q.empty() && (q.front() <= i-k)){
			q.pop_front();
		}
		while(!q.empty() && a[i] >= a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
    cout<<a[q.front()];
	
	return 0;
}
