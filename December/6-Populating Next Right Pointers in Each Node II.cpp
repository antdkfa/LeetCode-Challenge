/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<pair<Node*, int>> q;
        vector<Node*> v[6005];
        q.push({root, 0});
        v[0].push_back(root);
        while(!q.empty()){
            pair<Node*, int> now = q.front();
            q.pop();
            if(now.first->left) q.push({now.first->left, now.second+1}), v[now.second+1].push_back(now.first->left);
            if(now.first->right) q.push({now.first->right, now.second + 1}), v[now.second+1].push_back(now.first->right);
        }
        for(int i = 0;i<6005;i++){
            if(!v[i].size()) break;
            for(int j = 0;j<v[i].size() - 1;j++){
                v[i][j]->next = v[i][j + 1];
            }
        }
        return root;
    }
};
