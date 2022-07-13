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
        
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        vector<int> save[2005];
        while(!q.empty()) {
            pair<int,TreeNode*> now = q.front();
            q.pop();
            if(now.second == nullptr) continue;
            save[now.first].push_back(now.second->val);
            q.push({now.first+1, now.second->left});
            q.push({now.first+1, now.second->right});
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<2005;i++) {
            vector<int> now = save[i];
            if(!now.size()) break;
            ans.push_back(now);
        }
        
        return ans;
    }
};
