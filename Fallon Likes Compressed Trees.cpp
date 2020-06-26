#include<iostream>
#include<vector>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    vector<int> map[100001];

    int n, q;

    cin >> n >> q;

    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;

        map[u].push_back(v);
        map[v].push_back(u);
    }

    while (q--){
        int r;
        cin >> r;

        int ans = n - 1 - map[r].size();
        cout << ans << endl;
    }


    return 0;
}
