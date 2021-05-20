#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *createTreeFromTrav(int *inOrder, int *preOrder, int s, int e)
{
    static  int i = 0;
    if (s > e)
    {
        return NULL;
    }
    node *root = new node(preOrder[i]);

    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (inOrder[j] == preOrder[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreeFromTrav(inOrder, preOrder, s, index - 1);
    root->right = createTreeFromTrav(inOrder, preOrder, index + 1, e);
    return root;
}

vector<int> v;
void printChildrenAtK(node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, print it
    if (k == 0)
    {
        // cout << root->data << " ";
        v.push_back(root->data);
        return;
    }

    printChildrenAtK(root->left, k - 1);
    printChildrenAtK(root->right, k - 1);
}

int printkdistanceNode(node *root, int target, int k)
{
    if (root == NULL)
        return -1;

    if (root->data == target)
    {
        printChildrenAtK(root, k);
        return 0;
    }

    // Recursive call for left subtree
    //distanceLeft is Distance of root's left child from target
    int distanceLeft = printkdistanceNode(root->left, target, k);

    // Check if target node was found in left subtree
    if (distanceLeft != -1)
    {
        // If root is at distance k from target, print root
        if (distanceLeft + 1 == k)
        {
            v.push_back(root->data);
        }

        // Else go to right subtree and print all k-distanceLeft-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printChildrenAtK(root->right, k - distanceLeft - 2);

        // Add 1 to the distance and return value for parent calls
        return 1 + distanceLeft;
    }

    //Try the same for right subtree as well
    int distanceRight = printkdistanceNode(root->right, target, k);
    if (distanceRight != -1)
    {
        if (distanceRight + 1 == k)
        {
            v.push_back(root->data);
        }
        else
            printChildrenAtK(root->left, k - distanceRight - 2);

        return 1 + distanceRight;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    int inOrder[n], preOrder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    node *root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int k, target;
        cin >> target >> k;
        v.clear();
        printkdistanceNode(root, target, k);
        if (v.size() == 0)
        {
            cout << "0";
        }
        else
        {
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
