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
class Solution {
public:
    int ret = 0;

    void dfs(TreeNode* current, int depth)
    {
        if(current->left == nullptr && current->right == nullptr)
            ret = max(ret, depth);

        if(current->left != nullptr) dfs(current->left, depth+1);
        if(current->right != nullptr) dfs(current->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        
        if(root != nullptr) dfs(root, 1);

        return ret;
    }
};