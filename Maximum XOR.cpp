#include "iostream"
using namespace std;
#define int long long

signed main()
{
    int x,y;
    cin>>x>>y;
    int num = x^y;
    int msb=0;
    while(num!=0) {
        num=num>>1;
        msb++;
    }
    int result = 1;
    while(msb--) {
        result=result<<1;
    }
    cout<<result-1;

    return 0;
}
