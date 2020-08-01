#include<iostream>
#include<queue>
using namespace std;
int main(){
	long long int n,k;
	cin>>n>>k;
	priority_queue<long long int> pq;
	for(int i=0; i<n; i++){
		long long int itr,x,y;
		cin>>itr;
		if(itr==1){
			cin>>x>>y;
			long long int distance = (x*x)+(y*y);
			if(pq.size()<k){
				pq.push(distance);
			}
			else if(distance<pq.top()){
				pq.pop();
				pq.push(distance);
			}
		}
		else if(itr==2){
			cout<<pq.top()<<endl;
		}
	}
}
