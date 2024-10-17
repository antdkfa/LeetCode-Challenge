class Solution {
public:
    int maximumSwap(int num) {
        stack<int> s;
        while(num != 0) {
            s.push(num % 10);
            num /= 10;
        }

        int token[15] = {}, sz = 0;
        while(!s.empty()) {
            token[sz++] = s.top();
            s.pop();
        }

        for(int i=0;i<sz;i++) {
            int biggerIdx = -1;
            int biggerValue = -1;
            for(int j=i+1;j<sz;j++) {
                if(token[i] < token[j]) {
                    if(biggerValue <= token[j]) {
                        biggerValue = token[j];
                        biggerIdx = j;
                    }
                }
            }
            if(biggerIdx != - 1) {
                token[biggerIdx] = token[i];
                token[i] = biggerValue;
                break;
            }
        }

        int ans = 0;
        for(int i=sz-1, tmp = 1;i>=0;i--,tmp*=10) {
            ans += token[i] * tmp;
        }
        return ans;
    }
};
