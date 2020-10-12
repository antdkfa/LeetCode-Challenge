class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length()) return false;
        int cnt = 0;
        for(int i = 0;i<A.length();i++) if(A[i] != B[i]) cnt++;
        if(!cnt) {
            int used[30] = {0, };
            for(int i = 0;i<A.length();i++){
                used[A[i] - 'a']++;
                if(used[A[i] - 'a'] >= 2) return true;
            }
            return false;
        }
        else if(cnt == 2) {
            int dif[5] = {0, };
            int idx = 0;
            for(int i = 0;i<A.length();i++){
                if(A[i] != B[i]) dif[idx++] = i; 
            }    
            if(A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]]) return true;
            else return false;
        }
        else return false;
    }
};
