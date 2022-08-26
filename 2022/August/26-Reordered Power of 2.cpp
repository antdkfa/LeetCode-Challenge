class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int now = 1;
        int i=1;
        int used[100][15] = {};
        used[0][1] = 1;
        for(i;now<=1000000000;i++) {
            now*=2;      
            string str = to_string(now);
            for(int j=0;j<str.length();j++) {
                used[i][str[j]-'0']++;
            }
        }
        
        int usedN[15] = {};
        string tmp = to_string(n);
        for(int i=0;i<tmp.length();i++) {
            usedN[tmp[i] - '0']++;
        }
        for(int s=0;s<=i;s++) {
            string now = to_string(n);
            bool flag = true;
            for(int j=0;j<10;j++) {
                if(used[s][j] != usedN[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
