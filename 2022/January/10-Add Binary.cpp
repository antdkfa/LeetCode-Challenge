class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length(), blen = b.length();
        int nextArr[4] = {0,0,1,1};
        char val[4] = {'0','1','0','1'};
        
        string ans = "";
        int next = 0;
        for(int i=alen-1,j=blen-1;i>=0||j>=0;i--,j--) {
            int nowA = i >= 0 ? a[i] - '0' : 0;
            int nowB = j >= 0 ? b[j] - '0' : 0;
            int sum = nowA + nowB + next;
            next = nextArr[sum];
            ans += val[sum];
        }
        
        if(next) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
