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
    int ans = 0, a[15] = {0, };
    
    void dfs(int size, int cnt[15], TreeNode *now){
        if(!now->left && !now->right) {
            int tmp = 0;
            for(int i = 0;i<10;i++){
                if(cnt[i] % 2) tmp++;
            }
            if(!tmp || (tmp == 1 && size % 2)) ans++;
            return;
        }
        if(now->left){
            cnt[now->left->val]++;
            dfs(size+1,cnt,now->left);
            cnt[now->left->val]--;
        }
        if(now->right){
            cnt[now->right->val]++;
            dfs(size+1,cnt,now->right);
            cnt[now->right->val]--;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        a[root->val]++;
        dfs(1,a,root);     
        return ans;
    }
};
