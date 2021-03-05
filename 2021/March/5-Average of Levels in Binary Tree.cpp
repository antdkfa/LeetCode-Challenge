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
        vector<double> ans;
        double visited[100005] = {0,};
        int cnt[100005] = {0, }, mxlevel = 0;
        TreeNode* tmp = root;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* now = q.front().first;
            int level = q.front().second;
            mxlevel = level;
            q.pop();
            visited[level]+=(double)now->val;
            cnt[level]++;
            if(now->left) q.push({now->left, level + 1});
            if(now->right) q.push({now->right, level + 1});
        }
        for(int i=0;i<=mxlevel;i++){
            ans.push_back(visited[i] / (double) cnt[i]);
        }
        return ans;
    }
};
