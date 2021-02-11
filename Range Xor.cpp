#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class node
{
public:
    node *l;
    node *r;
    vector<int> v;
	node(){
		l = r = NULL;   //update
	}
};
class trie
{
	private:
    node *root;
public:
    trie()
    {
        root = new node();
    }
    void insert(int n,int index){
        node *temp = root;
        for(int i=31 ; i>=0 ; i--){
            int bit = (n >> i) & 1; //Get ith bit
            if(bit == 0){
                //0 means node must have a left child to indicate it
                if(temp->l == NULL){
                    temp->l = new node();
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);  //update
                temp = temp->l ;
            }
            else {
                //1 means node must have a right node to indicate it  
                if(temp->r == NULL){
                    temp->r = new node() ;
                }
                //Insert the index of the number into the vector
                temp->v.push_back(index);  //update
                temp = temp->r ;
            }
        }
        temp->v.push_back(index);   //update
    }
    bool binarySearchRange(vector<int> v,int l,int r){
        //Vector v has indices stored of the numbers of which this bit is a part of 
        //Since the insertion took place in increasing order , vector is already sorted
        int s = 0;
        int e = v.size() - 1;
        while(s <= e){
            int mid = (s+e)/2 ;
            int val = v[mid];
            if(val >= l && val <= r){
                return true ;
            }
            else if(val < l){
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false ;
    }

    int maxXor(int value,int left,int right){
        //Maximise xor with value between index range <left,right>
        int currentXor = 0 ;
        node *temp = root;
        for(int j=31;j>=0;j--){
            //Proceed bit by bit
            int bit = (value >> j)&1;
            //To maximise xor , we need as many opposite bits as possible
            //Move right i.e. towards 1 bit side if value has a 0 bit at jth position
            if(bit == 0){
                //Value has a 0 bit at jth pos 
                //Get a number with 1 bit , move right if there is a right child node between the <left,right> range
                if(temp->r != NULL && binarySearchRange(temp->r->v,left,right)){
                    temp = temp->r ;
                    currentXor += (1<<j) ;  //Add the number with jth bit set to the currentXor
                }
                else {
                    //Else move left
                    temp = temp->l ;
                }
            }
            else {
                //Value has 1 bit at jth pos , move left if possible
                if(temp->l != NULL && binarySearchRange(temp->l->v,left,right)) {
                    temp = temp->l ;
                }
                else {
                    temp = temp->r ;
                    currentXor += (1<<j);   //Add the number with jth bit set to the currentXor
                }
            }
        }
        return currentXor ;
    }

};
int main()
{
    int n;
    cin >> n;
    trie t;
    int q, j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> q;

        if (q == 0)
        {
            int x;
            cin >> x;
             // a.push_back(x);  not needed
            t.insert(x, j);
            j++;
            //cout<<"h";
        }
        else
        {
            int l, r, y;
            cin >> l >> r >> y;
            cout <<  t.maxXor(y, l - 1, r - 1);  //update
            cout <<  endl;
        }
    }
}
