#include <iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<climits>
using namespace std;
class hash_fn{
    public:
    size_t operator()(const pair<int,int>&p) const{
        return p.first+p.second;
    }
};
int main() {
    int t;
    cin>>t;

    while(t--){
        vector<int> v;
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        unordered_map<pair<int,int>,int,hash_fn> m;
        int sum;
        cin>>sum;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]+v[j]==sum){
                    m[make_pair(v[i],v[j])]=sum;
                }
            }
        }

        int diff=INT_MAX;
        int val1,val2;

        for(auto x:m){
            if(abs(x.first.first-x.first.second)<diff){
                diff=abs(x.first.first-x.first.second);
                val1=x.first.first;
                val2=x.first.second;
            }
        }

        if(val1>=val2){
            cout<<"Deepak should buy roses whose prices are "<<val2<<" and "<<val1<<"."<<endl;
        }else{
            cout<<"Deepak should buy roses whose prices are "<<val1<<" and "<<val2<<"."<<endl;
        }
    }

    return 0;
}
