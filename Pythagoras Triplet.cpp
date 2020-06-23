#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int
int main(){
    ll x;

    while( cin >> x){
        if(x < 3){ printf("-1\n");  continue; }

        if(x & 1)  printf("%lld %lld", (x*x-1)/2, (x*x+1)/2);
        else{

            printf("%lld %lld", ((x*x)/4)-1, ((x*x)/4)+1);
        }
    }
    return 0;
}
