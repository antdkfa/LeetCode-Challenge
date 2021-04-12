class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int s = 1, e = n, flag;
        for(int i=0;i<k;i++){
            if(!flag) ans.push_back(s++), flag = 1;
            else ans.push_back(e--), flag = 0;
        }
        if(flag) for(int i=s;i<=e;i++) ans.push_back(i);
        else for(int i=e;i>=s;i--) ans.push_back(i);
        return ans;
    }
};
