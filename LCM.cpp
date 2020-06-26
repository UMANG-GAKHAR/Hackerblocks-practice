#include<iostream>
using namespace std;
int main() {
    int num1,num2;
    cin >> num1>>num2;

    if(num1>num2){
        int temp = num2;
        num2=num1;
        num1=temp;
    }

    int lcm=num2;
    while(lcm>0){
        if(lcm%num2==0 && lcm%num1==0){
            break;
        }
        lcm++;
    }
    cout << lcm << std::endl;
    return 0;
}
