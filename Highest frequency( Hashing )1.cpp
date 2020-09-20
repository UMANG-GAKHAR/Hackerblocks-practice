#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> m; //Key,Freq pair
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int maxFreq = 0;
    int ans = 0;
    for (auto it : m)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            ans = it.first;
        }
    }
    cout << ans ;

    return 0;
}
