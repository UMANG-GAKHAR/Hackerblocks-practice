#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
#include <cstring>
using namespace std;
unordered_map < int , list<int> > adjList;
long long int ans = 0;
bool dp[5009][5009] = {0};
// vector<int> arr(5009);
int x;
int n;
unordered_map<int , bool> m;

void target_subset_sum(vector<int> arr) 
{
    x = arr.size();
    memset(dp , 0 , sizeof dp);
    for (int i = 0 ; i <= arr.size() ; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j <= n - 2 ; j++) {
        dp[0][j] = false;
    }

    for (int i = 1 ; i <= x ; i++) {
        for (int j = 1  ; j <= n - 2 ; j++) {
            if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = (dp[i - 1][j] or (dp[i - 1][j - arr[i - 1]]));
            }
        }
    }
    for (int j = 1; j <= n - 2 ; j++) {
		if (m.count(j) == 0 and dp[x][j]) {
			ans += 1;
			m[j] = 1;
		}
    }
    return;
}

int dfs(int src , int par) {
    int c = 0;
    int sum = 0;
    vector<int> arr;
    for (auto x : adjList[src]) {
        if (x != par) {
            int a = dfs(x , src);
            sum += a;
            arr.push_back(a);
        }
    }

    if (arr.size()) {
        arr.push_back(n - (sum + 1));
        target_subset_sum(arr);
    }
    return sum + 1;
}


int main() {

    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int x , y;
        cin >> x >> y ;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(1 , 0);

    cout << ans << endl;
    return 0;
}
