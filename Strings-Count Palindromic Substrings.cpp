#include<iostream>
using namespace std;

bool isPalindrome(string str){
    for (int i = 0; i<str.length(); i++) {
        if(str[i]!=str[str.length()-1]){
            return false;
        }

    }

    return true;
}


int main() {
    string str;
    cin >> str;

    int count=0;
    for ( int i = 0; i<str.length(); i++) {
        for ( int j = i; j<str.length(); j++) {

            string s = "";
            for (int k = i; k <=j; k++) {
                s+=str[k];
            }
            if(isPalindrome(s)){
                count++;
            }
        }
    }

    cout << count <<endl;
    return 0;
}
