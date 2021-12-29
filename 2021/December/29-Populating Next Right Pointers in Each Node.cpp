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
    map<int, Node*> m;
    
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);
        int num = 1;
        while(!q.empty()){
            Node*now = q.front();
            m[num++] = now;
            q.pop();
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        int tmp = 2;
        for(int i = 1;i<num;i++){
            if(i == tmp - 1) tmp <<=1;
            else m[i]->next = m[i+1];
        }
        return root;
    }
};
