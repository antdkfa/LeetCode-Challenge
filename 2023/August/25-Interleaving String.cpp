class Solution {
public:
    bool ans, visited[105][105];
    void rec(int l, int r, string s1, string s2, string s3) {
        if(l == s1.length() && r == s2.length()) {
            ans = true;
            return;
        }
        if(l<s1.length() && s1[l] == s3[l+r] && !visited[l+1][r]) {
            visited[l+1][r] = true;
            rec(l+1,r,s1,s2,s3);
        }

        if(r<s2.length() && s2[r] == s3[l+r] && !visited[l][r+1]) {
            visited[l][r+1] = true;
            rec(l,r+1,s1,s2,s3);
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        rec(0,0,s1,s2,s3);
        return ans;
    }
};
