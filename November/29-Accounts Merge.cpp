class Solution {
public:
    unordered_map<string, string> m;

    string find(string mail){
        return m[mail] == mail ? mail : find(m[mail]);
    }
        
    unordered_map<string, string> m2n;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto account : accounts){
            for (int i = 1; i < account.size(); i++){
                m2n[account[i]] = account[0];
            }
            
            for (int i = 1; i < account.size(); i++)
                if (!m.count(account[i])){
                    m[account[i]] = account[i];
                }
            
            for (int i = 2; i < account.size(); i++){
                m[find(account[i])] = find(account[1]);
            }
        }
        unordered_map<string, unordered_set<string>> m2ms;
        for (auto account : accounts){
            for (int i = 1; i < account.size(); i++){
                m2ms[find(account[i])].insert(account[i]);
            }
        }

        vector<vector<string>> res;
        for (auto kv: m2ms){
            vector<string> tmp;
            tmp.push_back(m2n[kv.first]);

            for (auto s: kv.second)
                tmp.push_back(s);
            
            sort(tmp.begin() + 1, tmp.end());
            
            res.push_back(tmp);
        }
        return res;
    }
};
