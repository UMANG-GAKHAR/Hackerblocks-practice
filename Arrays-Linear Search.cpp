
#include<iostream>
using namespace std;
int main() {
    long long int n, i;
    cin >> n;
    long long int arr[n];
    for (i = 0; i < n ; i++)
        cin >> arr[i];

    long long int num;
    cin >> num;

    for (i = 0; i < n; i++)
    {
        if (num == arr[i])
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
