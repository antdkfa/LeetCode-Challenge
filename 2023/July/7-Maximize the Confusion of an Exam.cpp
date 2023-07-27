class Solution {
public:
    int solve(string answerKey, int k, char change) {
        int s = 0, e = 0, n = answerKey.length(), ans = -1e9;
        while(s<n && e<n) {
            if(answerKey[e] == change) {
                if(0<k) {
                    k--;
                    e++;
                } else {
                    if(answerKey[s] == change) {
                        k++;
                    }
                    s++;
                }
            } else e++;
            ans = max(ans, e-s+1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F')) - 1;
    }
};
