#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float n;
    cin >> n;
    cout << fixed << setprecision(2) << n*9/(float)100;
    return 0;
}
