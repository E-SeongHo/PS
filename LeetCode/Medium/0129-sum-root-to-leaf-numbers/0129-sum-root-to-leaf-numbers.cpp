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
    void ApplySum(vector<int>& records)
    {
        int size = records.size();
        int sum = 0;

        for(auto record : records)
        {
            sum += pow(10, size-1) * record;
            size--;
        }

        summation += sum;
    }
    void DFS(TreeNode* current, vector<int>& records)
    {
        if(current->left == nullptr && current->right == nullptr)
        {
            ApplySum(records);
            return;
        }

        if(current->left != nullptr)
        {
            records.push_back(current->left->val);
            DFS(current->left, records);
            records.pop_back();
        }

        if(current->right != nullptr)
        {
            records.push_back(current->right->val);
            DFS(current->right, records);
            records.pop_back();
        }
    }

    int sumNumbers(TreeNode* root) {
        vector<int> records;
        records.push_back(root->val);
        DFS(root, records);

        return summation;
    }

public: 
    int summation = 0;
};