class Solution {
public:
    int nextGreaterElement(int n) {
        string token ="", mx ="2147483647";
        vector<string> ans;
        while(n){
            token += n%10 +'0';
            n/=10;
        }
        reverse(token.begin(), token.end());
        int len = token.length(),idx = 1e9;
        for(int i = len - 2;i>=0;i--) {
            for(int j = len-1;j>i;j--){
                if(token[i] < token[j]){
                    if(idx == 1e9 || token[idx] >= token[j]){
                        idx = j;
                    }
                }
            }
            if(idx != 1e9) {
                swap(token[i],token[idx]);
                for(int j = i + 1;j<len;j++){
                    for(int k=j+1;k<len;k++){
                        if(token[j] > token[k]) swap(token[j],token[k]);
                    }
                }
                break;   
            }
        }
        if(idx == 1e9 || (token.length() >= mx.length() && token > mx)) return -1;
        return stoi(token);
    }
};
