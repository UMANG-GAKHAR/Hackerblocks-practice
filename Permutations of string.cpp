#include<iostream>
#include<cstring>
using namespace std;
int r=0;
void Permutations(char arr[],char storage[][20],char print[],int beg,int n,int i){
    if(beg==n){
        print[i]='\0';
        strcpy(storage[r],print);
        r++;
        return;
    }
    for(int x=0;x<n-beg;++x){
        swap(arr[beg],arr[beg+x]);
        print[i]=arr[beg];
        Permutations(arr,storage,print,beg+1,n,i+1);
        swap(arr[beg],arr[beg+x]);
    }
}
void Display(char storage[][20],int rows){
    for(int i=0;i<rows;++i){
        cout<<storage[i]<<" ";
    }
}
bool isLargest(char x[], char y[]){
    int i = 0;
    // int j = 0;
    while(x[i] != '\0' && y[i] != '\0'){
        if (x[i] == y[i]){
            i++;    
            continue;
        }else if (x[i] > y[i]) {
            return true;
        }else {
            return false;
        }
    }
    if (x[i] == '\0') return false;
    return true;
}
void BubbleSort(char arr[][20],int n){
    if(n==1)return;
    BubbleSort(arr,n-1);
    if(isLargest(arr[n-2],arr[n-1])){
        char tmp[20];
        strcpy(tmp,arr[n-2]);
        strcpy(arr[n-2],arr[n-1]);
        strcpy(arr[n-1],tmp);
        BubbleSort(arr,n-1);
    }
}
int main() {
    char arr[20];
    cin>>arr;
    int n=strlen(arr);
    char print[20],storage[100000][20];
    Permutations(arr,storage,print,0,n,0);
    cout<<r<<endl;
    BubbleSort(storage,r);
    Display(storage,r);
}
