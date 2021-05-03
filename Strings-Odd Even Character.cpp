#include<iostream>
using namespace std;
int main() {
    char str[1001];
    cin >> str;
    for (int i = 0; str[i] !='\0'; i++) {
        if(i&1){
            str[i]=str[i]-1;
        }else {
            str[i]=str[i]+1;
        }
    }
    cout << str <<endl;
    return 0;
}
