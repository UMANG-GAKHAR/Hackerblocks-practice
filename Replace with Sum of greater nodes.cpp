#include<bits/stdc++.h>
using namespace std;
int sum = 0;

class node {
public:
	int data;
	node *left;
	node *right;

	node( int d ) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

void printPre( node *root ) {
	if ( root == NULL ) {
		return;
	}

	cout << root->data << " ";
	printPre( root->left );
	printPre( root->right );
}

node * buildAHeightBalancedBSTFromAnArray( int *a , int si , int ei ) {
	if ( si > ei ) {
		return NULL;
	}

	int mid = ( si + ei ) / 2;
	node *root = new node( a[mid] );

	node *leftHead = buildAHeightBalancedBSTFromAnArray( a , si , mid - 1 );
	node *rightHead = buildAHeightBalancedBSTFromAnArray( a , mid + 1 , ei );

	root->left = leftHead;
	root->right = rightHead;

	return root;
}

void replaceEachNodeWithSumOfGreaterThanEqualNodes( node *root ) {
	if ( root == NULL ) {
		return ;
	}

	replaceEachNodeWithSumOfGreaterThanEqualNodes( root->right );

	root->data += sum;
	sum = root->data;

	replaceEachNodeWithSumOfGreaterThanEqualNodes( root->left );
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int in[1005];

	cin >> n;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> in[i];
	}

	node *root = buildAHeightBalancedBSTFromAnArray( in , 0 , n - 1 );

	replaceEachNodeWithSumOfGreaterThanEqualNodes( root );

	printPre( root );
}
