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
    bool pathSum(TreeNode* node, int targetSum, int currentSum)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            return (currentSum == targetSum);
        }
        
        bool left, right;
        if(node->left != nullptr) left = pathSum(node->left, targetSum, currentSum + node->left->val);
        if(node->right != nullptr) right = pathSum(node->right, targetSum, currentSum + node->right->val);
        
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return false;
        
        return pathSum(root, targetSum, root->val);
    }
};