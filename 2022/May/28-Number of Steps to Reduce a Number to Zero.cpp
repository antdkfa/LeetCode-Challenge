class Solution {
public:
    int numberOfSteps (int num) {
        int ans=0;
        while(num){
            if(num%2)num--,ans++;
            else num/=2,ans++;
        }
        return ans;
    }
};
