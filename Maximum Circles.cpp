#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(const pair<int,int> &a, 
              const pair<int,int> &b)
{
    if(a.second==b.second){
        return a.first<b.first;
    }
	return a.second<b.second;
}
int main() {
	int n;
	cin>>n;
	vector<pair<long,long>> v;
	long x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		v.push_back(make_pair(x-y,x+y));
	}
	sort(v.begin(),v.end(),compare);

	long count=1;
	long last=v[0].second;
	for(int i=1;i<n;i++)
	{
		if(v[i].first>=last)
		{
		    count++;
		    last=v[i].second;
		}
	}
	cout<<n-count;

	return 0;
}
