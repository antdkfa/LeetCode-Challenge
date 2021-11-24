class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        for(int i=0;i<firstList.size();i++) {
            int s1 = firstList[i][0], e1 = firstList[i][1];
            for(int j=0;j<secondList.size();j++) {
                int s2 = secondList[j][0], e2 = secondList[j][1];
                vector<int> tmp;
                if(s1 <= s2) {
                    if(e1 < s2) continue;
                    else {
                        tmp.push_back(s2);
                        tmp.push_back(min(e1,e2));
                        ans.push_back(tmp);
                    }
                } else {
                    if(e2 < s1) continue;
                    else {
                        tmp.push_back(s1);
                        tmp.push_back(min(e1,e2));
                        ans.push_back(tmp);
                    }
                }
            }
        }
        return ans;
    }
};
