#include<bits/stdc++.h>
using namespace std;
struct node{
    public :
    node*left;
    node* right;
    node(){
        left = right = NULL;
    }
};
int FindmaxXor(node* head , int* arr, int n , int el){

    int max_xor = INT_MIN;
    node* curr = head;
    int value = el;
    int curr_xor = 0;
    for(int j = 31 ; j >= 0 ; j--){
        int b = (value >> j)& 1;
        if( b== 0){
            if(curr->right != NULL){
                curr = curr->right ;
                curr_xor += (int)pow(2, j);
            }else
            curr = curr->left;

        }else{
            if(curr->left != NULL){
                curr = curr->left;
                curr_xor += (int)pow(2, j);
            }else curr = curr->right;
        }
    }
    if(curr_xor  > max_xor) max_xor = curr_xor;
    return max_xor;


}
void insert(int n, node* head){
  node* curr = head;
    for(int i = 31; i >=0 ; i--){
        int bit  = (n >>  i)&1 ;
        if(bit == 0){
            if(curr->left == NULL)
            curr->left = new node();
            curr = curr->left;
        }else{
            if(curr->right == NULL) 
            curr->right = new node();

            curr = curr->right;    
        }
    }
}
int main(){
    int n;
    cin >> n;
    int *a= new int[n];
    int *b=new int[n];
    for(int i = 0 ; i < n ; i++)
    cin >> a[i];
    for(int i=0;i<n;i++){
        if(i==0){
            b[i]=a[i];
        }else{
            b[i]=a[i]^b[i-1];
        }
    }
	// for(int x  : b)cout << x <<" ";
    node* head = new node();
    int result = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        insert(b[i], head);
        int x = FindmaxXor(head, b, n , b[i]);
        result = max(result, x);
	}    
cout << result;

}
