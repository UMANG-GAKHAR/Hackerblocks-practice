#include<bits/stdc++.h>
using namespace std;
int main() {
long long n, k, x, t, ans;
cin >> n >> k;
t = n % k;
x = n / k;
ans = ((x * (x - 1)) / 2) * (k - t);
x = (n / k) + 1;
ans += ((x * (x - 1)) / 2) * t;
cout << ans;
return 0;
}
