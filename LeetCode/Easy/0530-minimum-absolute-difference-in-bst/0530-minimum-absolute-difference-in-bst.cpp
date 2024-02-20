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
    int ret = INT_MAX;
    int prev = -1;
    void inorder(TreeNode* current)
    {
        if(current->left != nullptr) inorder(current->left);
        if(prev >= 0) ret = min(current->val - prev, ret);
        prev = current->val;
        if(current->right != nullptr) inorder(current->right);
        
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        
        return ret;
    }
};