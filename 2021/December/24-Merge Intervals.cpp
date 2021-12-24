class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        typedef pair<int,int>p;
        vector<p> input;
        for(int i=0;i<intervals.size();i++) {
            input.push_back({intervals[i][0], intervals[i][1]});
        }
        sort(input.begin(), input.end());
        
        int s=input[0].first, e = input[0].second;
        vector<vector<int>> ans;
        for(int i=1;i<input.size();i++) {
            if(s<=input[i].first && input[i].first <= e) {
                e = max(e, input[i].second);
            } else {
                vector<int> tmp;
                tmp.push_back(s);
                tmp.push_back(e);
                ans.push_back(tmp);
                s = input[i].first, e = input[i].second;
            }
        }
        vector<int> tmp;
        tmp.push_back(s);
        tmp.push_back(e);
        ans.push_back(tmp);
        return ans;
    }
};
