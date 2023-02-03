class Solution {
public:

    string row[1005];

    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int idx = 0, dir=1;
        for(char now: s) {
            row[idx] += now;
            if(idx+dir == numRows) {
                dir = -1;
            } else if(idx + dir <0) {
                dir = 1;
            }
            idx+=dir;
        }

        string ans = "";
        for(int i=0;i<numRows;i++) {
            ans += row[i];
        }

        return ans;
    }
};
