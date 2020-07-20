#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<int, int> freq; // <Number,Frequency> pair
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        freq[temp]++;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (freq.find(temp) != freq.end() && freq[temp] > 0)
        {
            freq[temp]--; //Decrement frequency to ensure it is not repeated
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());

    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}

