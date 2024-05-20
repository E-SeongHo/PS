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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> averages;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        averages.push_back(0.0);
        
        int currentLevel = 0;
        int cnt = 0;
        while(!q.empty())
        {
            auto p = q.front(); q.pop();
            cout << p.first << " " << p.second->val << endl;
            
            if(p.first != currentLevel)
            {
                currentLevel++;
                averages.back() = averages.back() / cnt;
                
                averages.push_back(p.second->val);
                cnt = 1;
            }
            else 
            {
                averages.back() = averages.back() + p.second->val;
                cnt++;
            }
            
            if(p.second->left)  q.push({p.first+1, p.second->left});
            if(p.second->right) q.push({p.first+1, p.second->right});
        }
        
        averages.back() = averages.back() / cnt;
        
        return averages;
    }
};