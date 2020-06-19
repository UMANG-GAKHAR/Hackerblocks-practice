
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    string octal = "";
    while(n!=0){
        int r = n%8;
        n/=8;
        char c = r+'0';
        octal = c+octal;
    }
    cout << octal <<endl;
}
