#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[1000], n, m;
    cin >> n;
    for (int i = 0; i < n; i++ )
    {
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        next_permutation(arr, arr + m);
		for (int i = 0 ; i < m ; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
    }
    return 0;
}
