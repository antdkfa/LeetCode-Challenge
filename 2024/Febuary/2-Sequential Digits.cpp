class Solution {
public:
    vector<int> ans;
    void rec(int val, int idx, int low, int high) {
        int now = val * 10 + idx;
        if(high < now || idx == 10) return;
        if(low <= now && now <= high) ans.push_back(now);
        rec(now,idx+1,low,high);
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<10;i++) {
            rec(0,i,low,high);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
