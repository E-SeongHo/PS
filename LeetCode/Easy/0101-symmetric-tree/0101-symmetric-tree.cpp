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
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == nullptr && root2 != nullptr) return false;
        if(root1 != nullptr && root2 == nullptr) return false;
        if(root1 == nullptr && root2 == nullptr) return true;
        
        if(root1->val != root2->val) return false;
        else
        {
            bool out = isSymmetric(root1->left, root2->right);
            bool in = isSymmetric(root1->right, root2->left);
            return out && in;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return isSymmetric(root->left, root->right);
    }
};