#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

void PostOrder(Node* node)
{
    if(node->left) PostOrder(node->left);
    if(node->right) PostOrder(node->right);
    cout << node->data << "\n";
}
void PreOrder(Node* node)
{
    cout << node->data << "\n";
    if(node->left) PreOrder(node->left);
    if(node->right) PreOrder(node->right);
}

void InsertBST(Node* node, int value)
{
    if(value < node->data)
    {
        if(!node->left)
        {
            Node* n = new Node();
            n->data = value;
            node->left = n;
        }
        else
        {
            InsertBST(node->left, value);
        }
    }
    else
    {
        if(!node->right)
        {
            Node* n = new Node();
            n->data = value;
            node->right = n;
        }
        else
        {
            InsertBST(node->right, value);
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> order;
    int n;
    while(cin >> n)
        order.push_back(n);

    Node* root = new Node();
    root->data = order[0];

    Node* current = root;
    for(int i = 1; i < order.size(); ++i)
    {
        InsertBST(current, order[i]);
    }

    PostOrder(root);

    return 0;
}