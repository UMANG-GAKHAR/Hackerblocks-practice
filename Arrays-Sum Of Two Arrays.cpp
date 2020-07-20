#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int m,n,b,d,e;
    cin>>n;
    int arr1[n];
    for(int i =0;i<n;i++){
        cin>>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    int dig = 0 , c = 0 , i = n-1 , j = m-1;
    int mx = max(n , m);
    vector<int> vec;
    while(i>= 0  or j>=0 ){
        int sum = (i>=0 ? arr1[i] : 0 ) + ( j >=  0 ? arr2[j] : 0 );
        vec.push_back((c + sum%10)%10);
        c = sum/10;
        i-- , j--;
    }
    if(c) vec.push_back(c);
    reverse(vec.begin(), vec.end());
    for(int x : vec) cout << x<<", ";
    cout << "END";
    return 0;
}
