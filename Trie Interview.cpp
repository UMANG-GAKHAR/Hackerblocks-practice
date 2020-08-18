#include <bits/stdc++.h>
using namespace std ;

class node {
public :
    node *left ;
    node *right ;
    node(){
        left = right = NULL ; 
    }
};

class Trie {
private :
    node *root ;
public :
    Trie(){
        root = new node() ; 
    }
    void insert(int n){
        node *temp = root ;
        for(int i=31 ;i>=0;i--){
            int bit = (n >> i) & 1;
            if(bit == 0){
                if(temp->left == NULL){
                    temp->left = new node() ;
                }
                temp = temp->left ;
            }
            else {
                if(temp->right == NULL){
                    temp->right = new node() ;
                }
                temp = temp->right ;
            }
        }
    }
    int findMaxXorPair(int value){
        node *temp = root ;
        int currentXor = 0 ;
        for(int j=31 ;j>=0 ; j--){
            int bit = (value >> j) & 1;
            if(bit == 0){
                if(temp->right != NULL){
                    temp = temp->right ;
                    currentXor += (1<<j);
                }
                else {
                    temp = temp->left ;
                }
            }
            else {
                if(temp->left != NULL){
                    temp = temp->left ;
                    currentXor += (1<<j);
                }
                else {
                    temp = temp->right ;
                }
            }
        }
        return currentXor ; 
    }
};

int main() {
    int n ;
    cin >> n;
    int result = 0;
    int arr[n];
    int lbest[100000] ;
    int rbest[100000] ;
    int left_value = 0,right_value = 0;


    Trie tl;
    tl.insert(0);
    for(int i=0;i<n;i++){
        cin >> arr[i] ;
        left_value ^= arr[i];
        lbest[i] = max( (i == 0)? 0 : lbest[i-1] , tl.findMaxXorPair(left_value));
        tl.insert(left_value);
    }

    Trie tr ;
    tr.insert(0);
    for(int i=n-1;i>=0;i--){
        right_value ^= arr[i];
        rbest[i] = max((i == n - 1) ? 0 : rbest[i + 1],tr.findMaxXorPair(right_value));
        tr.insert(right_value);   
        int val = rbest[i] + (i == 0 ? INT_MIN : lbest[i - 1]);
        result = max(result,val);
    }


    cout << result ;

    return 0 ;
}
