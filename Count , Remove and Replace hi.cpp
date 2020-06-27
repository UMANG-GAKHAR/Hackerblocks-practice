#include<iostream>
#include<cstring>
using namespace std;
int ans=0;

//Function which count numbers of hi in the given string
void count(char arr[],int n){
    if(n==0){return;}
    count(arr,n-1);
    if(arr[n-1]=='i'&&arr[n-2]=='h'){
        ans++;
    }
}

//Function which replace hi to bye in the given string
void print1(char arr[],int n,int size){
    if(n==0){return;}
    if(arr[n-1]=='h'&&arr[n]=='i'){
        print1(arr,n-1,size);
        cout<<"bye";
    }
    else if(arr[n-1]=='i'&&arr[n-2]=='h'){
        print1(arr,n-1,size);
    }
    else{
        print1(arr,n-1,size);
        cout<<arr[n-1];
    }
}

//Function which remove or skip hi from the given strings.
void print2(char arr[],int n,int size){
    if(n==0){return;}
    if(arr[n-1]=='h'&&arr[n]=='i'){
        print2(arr,n-1,size);
    }
    else if(arr[n-1]=='i'&&arr[n-2]=='h'){
        print2(arr,n-1,size);
    }
    else{
        print2(arr,n-1,size);
        cout<<arr[n-1];
    }
}
int main() {
    char arr[100];
    cin>>arr;
    int n=strlen(arr);
    count(arr,n);
    cout<<ans<<endl;
    print2(arr,n,n);
    cout<<endl;
    print1(arr,n,n);
    cout<<endl;
    return 0;
}
