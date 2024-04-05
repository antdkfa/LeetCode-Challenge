class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0, gIdx = 0, sIdx = 0;
        while(gIdx < g.size() && sIdx < s.size()) {
            if(g[gIdx] <= s[sIdx]) {
                ans++, gIdx++, sIdx++;
            } else {
                sIdx++;
            }
        }

        return ans;
    }
};
