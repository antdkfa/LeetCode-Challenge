class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        set<int> container[30];
        for(int i=0;i<s.length();i++){
            container[s[i] - 'a'].insert(i);
        }
        
        int ans = 0;
        for(int i=0;i<words.size();i++){
            string now = words[i];
            int idx = 0;
            bool flag = true;
            for(int j=0;j<now.length();j++){
                auto it = container[now[j]-'a'].lower_bound(idx);
                if(it == container[now[j]-'a'].end()) {
                    flag = false;
                    break;
                }
                else {
                    idx = *it;
                    idx++;
                }
            }
            if(flag) {
                ans++;
            }    
        }
        return ans;
    }
};
