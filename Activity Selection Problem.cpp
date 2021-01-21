#include<bits/stdc++.h>
using namespace std;
bool mycompare(pair<int,int>a , pair<int,int>b){
	return a.second<b.second;	
}

int main() {
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>>v;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end(),mycompare);
		int Time_elapsed=0;
		int cnt=0;
		for(auto it:v){
			if(it.first>=Time_elapsed){
				cnt++;
				Time_elapsed=it.second;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
