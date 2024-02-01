/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> tree;
    int idx  = 0;

    BSTIterator(TreeNode* root) 
    {
        TreeNode* current = root;
        stack<TreeNode*> stack;
        stack.push(current);

        while(!stack.empty())
        {
            current = stack.top();
            if(current->left != nullptr)
            {
                stack.push(current->left);
                continue;
            }

            while(current->right == nullptr)
            {
                tree.push_back(current);
                stack.pop();
                if(stack.empty()) return;
                current = stack.top();
            }   

            tree.push_back(current);
            stack.pop();
            stack.push(current->right);
        }
    }
    
    int next() 
    {
        return tree[idx++]->val;
    }
    
    bool hasNext() 
    {
        return (idx <= tree.size()-1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */