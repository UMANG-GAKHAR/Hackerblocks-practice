#include<iostream>
#include<vector> 
#include<unordered_map>
using namespace std;
#define int long long int
vector<int> vec;
int n,n1,k;
 bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_map<int,int> dp;
        for(int i=0;i<nums.size();i++){
            if(dp.count(nums[i])>0 && (i-dp[nums[i]])<=k){
                return true;
            }
            dp[nums[i]]=i;
        }
        return false;
 }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    {   
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        cin >> k;
        if(containsNearbyDuplicate(vec,k)){
            cout << "true"<<endl;
        }
        else{
            cout << "false"<<endl;
        }

    }
    return 0;
}
