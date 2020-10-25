class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int s = 0, e = tokens.size() - 1, score = 0;
        sort(tokens.begin(),tokens.end());
        while(s<=e){
            int tmpP = P, tmps = 0;
            for(int i=s;i<=e;i++){
                if(tmpP>=tokens[i]) tmpP-=tokens[i], tmps++;
            }
            score = max(score,tmps);
            if(tokens[s] > P) break;
            P=P-tokens[s]+tokens[e],s++,e--;
            int tmpP2 = P, tmps2 = 0;
            for(int i =s;i<=e;i++){
                if(tmpP2 >= tokens[i]) tmpP2-=tokens[i], tmps2++;    
            }
            score = max(score, tmps2);
            if(tmps > tmps2) break;
        }
        return score;
    }
};
