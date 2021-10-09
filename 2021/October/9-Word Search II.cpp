class TrieNode {
public:
    bool end, inserted;
    vector<TrieNode*> letters;
    TrieNode (bool end=false, bool inserted=false, int size=26) {
        this->end = end;
        this->inserted = inserted;
        this->letters = vector<TrieNode*>(size, NULL);
    }
};

class Solution {
    typedef TrieNode node;
public:
    
    node* troot = NULL;
    node* insertWord(node *root, string &word, int i=0) {
        if (!root) return insertWord(new node(), word, i);
        if (i == word.size()) root->end = true;
        else root->letters[word[i] - 'a'] = insertWord(root->letters[word[i] - 'a'], word, i + 1);
        return root;
    }
    
    char fill = '#';    
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    string word;
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &word: words)
            troot = insertWord(troot, word);
        for (int row = 0; row < board.size(); row++)
            for (int col = 0; col < board[0].size(); col++)
                if (troot->letters[board[row][col] - 'a'])
                    dfs(board, row, col, troot);
        return ans;
    }
    void dfs(vector<vector<char>> &board, int x, int y, node *root) {
        if (!root or x < 0 or x >= board.size() or y < 0 or y >= board[0].size())
            return;
        if (board[x][y] == fill or !root->letters[board[x][y] - 'a'])
            return;
        word.push_back(board[x][y]);
        root = root->letters[board[x][y] - 'a'];
        if (root->end and not root->inserted) {
            root->inserted = true;
            ans.push_back(word);
        }
        char orig = board[x][y];
        board[x][y] = fill;
        for (int d = 0; d < 4; d++)
            dfs(board, x + dx[d], y + dy[d], root);
        board[x][y] = orig;
        word.pop_back();
    }
};
