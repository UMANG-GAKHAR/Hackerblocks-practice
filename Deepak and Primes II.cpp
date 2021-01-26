#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int pr[N+5] = {0};
vector<int> primes;
void seive()
{
    for(int i = 2; i <= N; i++)
    {
        if(pr[i] == 0)
        {
            primes.push_back(i);
            for(int j = i; j <= N; j += i)
            {
                pr[j] = 1;
            }
        }
    }
}

int main()
{
    
    seive();
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> m >> n;
        bool segment[n - m + 1];
        for(int i = 0; i < n-m+1; i++)segment[i] = 0;
        for(auto x:primes)
        {
            if(x*x > n)break;
            int start = (m+x-1)/x;
            start*=x;
            if(start==x)
                start+=x;
            for(int i = start; i <= n; i+=x)
            {
                segment[i - m] = 1;
            }
        }
        for(int i = m; i <= n; i++)
        {
            if(segment[i-m] == 0 and i != 1)cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}
