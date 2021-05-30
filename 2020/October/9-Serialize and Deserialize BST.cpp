/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *now = q.front();
            q.pop();
            if(now == NULL) ans += '-', ans += " ";
            else {
                ans+=(to_string(now->val));
                ans+=" ";
                if(now->left != NULL){
                    q.push(now->left);
                }
                else q.push(NULL);
                if(now->right != NULL){
                    q.push(now->right);
                }
                else q.push(NULL);
            }
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        int idx = 1;
        int d[100005] = { 0, };
        string now ="";
        for(int i = 0;i<data.length();i++){
            if(data[i] == ' '){
                if(now == "-"){
                    d[idx++] = -1; 
                }
                else{
                    d[idx++] = stoi(now);
                }
                now = "";
            }
            else{
                now += data[i];
            }
        }
        TreeNode * root = new TreeNode(d[1]);
        queue<TreeNode *> q;
        q.push(root);
        for(int i = 1;i<idx;i++){
            if(q.empty()) break;
            TreeNode * now = q.front();
            q.pop();
            if(d[i*2] != -1) {
                TreeNode * tmp = new TreeNode(d[i * 2]);
                now->left = tmp;
                q.push(tmp);
            }
            if(d[i * 2 + 1] != -1){
                TreeNode *tmp = new TreeNode(d[i*2 +1]);
                now->right = tmp;
                q.push(tmp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
