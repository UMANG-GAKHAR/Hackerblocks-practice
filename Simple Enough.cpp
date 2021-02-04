#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<iostream>  
#include<cmath>  
#include<queue>  
#include<functional>  
typedef long long LL;
using namespace std;
#define maxn 1000005
#define ll l,mid,now<<1  
#define rr mid+1,r,now<<1|1  
#define lson l1,mid,l2,r2,now<<1  
#define rson mid+1,r1,l2,r2,now<<1|1  
#define inf 0x3f3f3f3f  
const int mod = 1e9 + 7;
LL query(LL l1,LL r1,LL l2,LL r2,LL nownumber){
    if (l1 == r1)
        return nownumber;
    LL mid = l1 + r1 >> 1;
    LL a = 0, b = 0, c = 0;
    if (l2 < mid)
        a = query(l1, mid - 1, l2, r2, nownumber >> 1);
    if (r2 > mid)
        b = query(mid + 1, r1, l2, r2, nownumber >> 1);
    if (l2 <= mid && r2 >= mid)
        c = nownumber % 2;
    return a + b + c;
}
int main(){
    LL n,l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    LL len = 1;
    LL now = n;
    LL add = 2;
    while (now > 1){
        now >>= 1;
        len += add;
        add <<= 1;
    }
    printf("%lld\n", query(1, len, l, r, n));
}
