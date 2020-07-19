#include <iostream>
#include <vector>
using namespace std;

#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int

ll merge(vector<ll> &a, int start, int end) {
    if(start > end) {
        return 0;
    }

    int mid = (start+end)/2;

    ll count = 0;

    int i = start;
    int j = mid + 1;
    int k = 0 ;

    vector<ll> temp(end-start+1,0);

    while(i <= mid && j <= end) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    while(i <= mid) {
        temp[k++] = a[i++];
    }

    while(j <= end) {
        temp[k++] = a[j++];
        count += (mid - i + 1);
    }

    j = 0;
    for (i = start; i <= end; ++i) {
        a[i] = temp[j++];
    }

    return count;
}

ll inversionCount(vector<ll> &a, int start, int end) {
    if(start >= end) {
        return 0;
    }

    ll ans = 0;

    int mid = (start+end)/2;

    ans += inversionCount(a, start, mid);
    ans += inversionCount(a, mid+1, end);

    ans += merge(a, start, end);

    return ans;
}

int main() { 
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << inversionCount(a, 0, n-1) << endl;
    }

    return 0;
}
