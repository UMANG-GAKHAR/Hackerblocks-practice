#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>p;
    int count=0;
    for(int i=0;i<nums.size();i++)
    {
        if(count<k)
        {
            p.push(nums[i]);
            count++;
        }
        else 
        {
            if(nums[i]>p.top())
            {
                p.pop();
                p.push(nums[i]);
            }
        }
    }
    return p.top();
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.push_back(a);
    }
    cout<<findKthLargest(arr,k);
}

