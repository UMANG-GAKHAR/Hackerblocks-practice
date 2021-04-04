#include <iostream>
#define ll long long int
#define mod 1000000007
using namespace std;
ll x,y;
ll gcd(ll a,ll b){
    if(b == 0){
        return (a);
    }
    return gcd(b,(a%b));
}
void extendedeuclid(int a,int b){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    extendedeuclid(b,a%b);
    int cx = y;
    int cy = x-(a/b)*y;
    x = cx;
    y = cy;
}
ll findmod(ll a,ll b){
    if(gcd(a,b) != 1){
        return (45);
    }
    extendedeuclid(a,b);
    return x;
}
int main() {
    ll a,b;
    cin>>a;
    b = mod;
    // cout<<gcd(a,b)<<endl;
    ll c = 45;
    if(findmod(a,b) == c){
        cout<<"";
        return 0;
    }
    if(x<0){
        cout<<(x+b)<<endl;
    }
    else{
        cout<<x<<endl;
    }
    return 0;
}
