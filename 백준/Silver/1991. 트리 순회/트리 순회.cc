#include <iostream>
#include <vector>

using namespace std;

int N;
struct Node
{
    char data;
    Node* left;
    Node* right;
};

void Preorder(Node* node)
{
    cout << node->data;
    if(node->left != nullptr) Preorder(node->left);
    if(node->right != nullptr) Preorder(node->right);
}

void Inorder(Node* node)
{
    if(node->left != nullptr) Inorder(node->left);
    cout << node->data;
    if(node->right != nullptr) Inorder(node->right);
}

void Postorder(Node* node)
{
    if(node->left != nullptr) Postorder(node->left);
    if(node->right != nullptr) Postorder(node->right);
    cout << node->data;
}

int main()
{
    cin >> N;
    vector<Node*> nodes(N);
    for(int i = 0; i < N; ++i)
    {
        nodes[i] = new Node();
    }

    for(int i = 0; i < N; ++i)
    {
        char data, left, right;
        cin >> data >> left >> right;

        int idx = data - 'A';
        nodes[idx]->data = data; 

        if(left != '.') nodes[idx]->left = nodes[left-'A'];
        else nodes[idx]->left = nullptr;

        if(right != '.') nodes[idx]->right = nodes[right-'A'];
        else nodes[idx]->right = nullptr;
    }

    Preorder(nodes[0]);
    cout << "\n";
    Inorder(nodes[0]);
    cout << "\n";
    Postorder(nodes[0]);
    cout << "\n";

    return 0;
}