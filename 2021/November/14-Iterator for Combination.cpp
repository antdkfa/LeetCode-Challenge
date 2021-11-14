class CombinationIterator {
public:
    
    string str;
    int len;
    vector<bool> V;
    int queryCnt = 0;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        len = characters.size();
        queryCnt = 0;
        for(int i = 0; i < len; i++)
            V.push_back(i < combinationLength);
    }
    
    string next() {
        if(queryCnt++) prev_permutation(V.begin(), V.end());
        
        string ans = "";
        for(int i = 0; i < len; i++)
            if(V[i]) ans += str[i];
        
        return ans;
    }
    
    bool hasNext() {
        auto P = V;
        return prev_permutation(P.begin(), P.end());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
