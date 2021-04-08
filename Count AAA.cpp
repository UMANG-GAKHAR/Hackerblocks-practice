#include<iostream>
#include<cstring>
using namespace std;
int ans1=0;
void count1(char arr[],int n){
    if(n<=0){return;}
    count1(arr,n-1);
    if(arr[n-1]=='a'&&arr[n-2]=='a'&&arr[n-3]=='a'){
        ans1++;
    }
}
int ans2=0;
//Function to check number of non-overlapping aaa in the string
void count2(char arr[],int n){
    if(n<=0){return;}
    if(arr[n-1]=='a'&&arr[n-2]=='a'&&arr[n-3]=='a'){
        ans2++;
        count2(arr,n-3);
    }
    else{count2(arr,n-1);}
}
int main() {
    char arr[100];
    cin>>arr;
    int n=strlen(arr);
    count1(arr,n);
    count2(arr,n);
    cout<<ans1<<endl<<ans2;;
}
