#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j <= i) {
        cout << j << "\t";
      } else
        cout << "\t";
    }
    if (i == n) {
      for (int l = n - 1; l >= 1; l--) {
        if (l <= i) {
          cout << l << "\t";
        } else
          cout << "\t";
      }
    } else {
      for (int l = n - 1; l >= 1; l--) {
        if (l <= i) {
          cout << l << "\t";
        } else
          cout << "\t";
      }
    }

    cout << endl;
  }
  return 0;
}
