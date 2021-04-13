#include <bits/stdc++.h>
using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int ms;
    int sum;
    MovingAverage(int size) {
        ms=size;
        sum=0;
    }
    double next(int val) {
        q.push(val);
        sum+=val;
        if(q.size()>ms){
            sum-=q.front();
            q.pop();
        }
        double ans=(double)(sum)/q.size();
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    int ws;
    cin>>ws;
    MovingAverage odj(ws);
    int num;
    cin>>num;
    while(num!=-1)
    {
        cout<<odj.next(num)<<" ";
        cin>>num;
    }

    return 0;
}

