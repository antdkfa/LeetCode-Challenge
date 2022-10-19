class Solution {
public:
    typedef pair<int,string>is;
    static bool cmp(is a, is b) {
        if(a.first == b.first) {
            return a.second < b.second;
        } else return a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int cnt = 0;
        sort(words.begin(), words.end());
        string now =words[0];
        words.push_back("!EOF!");
        vector<is> v;
        
        for(int i=0;i<words.size();i++) {
            if(now == words[i]) cnt++;
            else {
                v.push_back({cnt,now});
                now=words[i];
                cnt=1;
            }
        }
        sort(v.begin(), v.end(), cmp);
        
        vector<string>ans;
        for(int i=0;i<k;i++) {
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};
