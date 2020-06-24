#include <iostream>
#include <string>
using namespace std;

int main() {
    char str[1000];
    int nstr[2000];
    cin>>str;
    int i=1;
    cout<<str[0];
    while(str[i]!='\0'){
        nstr[i]=int(str[i])-int(str[i-1]);
        cout<<nstr[i]<<str[i];
        i++;
    }
    return 0;
}
