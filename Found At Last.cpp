#include <bits/stdc++.h>
using namespace std;

int lastIndex(const vector<int> &arr,int key,int i) {
    if(i == arr.size()) {
        return -1;
    }

    int nextAns = lastIndex(arr, key, i + 1);
    if(nextAns !=-1)
        return nextAns;

    if(arr[i] == key)
        return i;

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << lastIndex(arr, key,0);

    return 0;
}
