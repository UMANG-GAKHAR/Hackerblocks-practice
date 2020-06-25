#include <bits/stdc++.h>
using namespace std;

int countStrUtil(int dp[][2][3], int n, int bCount = 1, int cCount = 2)
{
    // Base cases
    if (bCount < 0 || cCount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bCount == 0 && cCount == 0)
        return 1;

    // if we had saw this combination previously
    if (dp[n][bCount][cCount] != -1)
        return dp[n][bCount][cCount];

    int res = countStrUtil(dp, n - 1, bCount, cCount);
    res += countStrUtil(dp, n - 1, bCount - 1, cCount);
    res += countStrUtil(dp, n - 1, bCount, cCount - 1);

    return (dp[n][bCount][cCount] = res);
}


int countStr(int n)
{
    int dp[n + 1][2][3];
    memset(dp, -1, sizeof(dp));
    return countStrUtil(dp, n);
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        cout << countStr(n) << endl;
    }

    return 0;
}
