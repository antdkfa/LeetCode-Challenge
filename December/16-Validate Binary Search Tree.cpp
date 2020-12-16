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
    typedef pair<int,int> p;
    bool ans = true;
    p dfs(TreeNode *now){
        if(!now->left && !now->right) return { now->val, now->val };
        p lnext= {0,0},rnext={0,0};
        if(now->left) { 
            lnext = dfs(now->left);
            if(lnext.second >= now->val) ans = false;        
        }
        else lnext = {now->val,now->val};
        if(now->right) {
            rnext = dfs(now->right);
            if(rnext.first <= now->val) ans = false;
        }
        else rnext = {now->val,now->val};
        return { min( min(lnext.first,rnext.first), now->val), max(max(rnext.second, lnext.second), now->val) };
    }
    
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
