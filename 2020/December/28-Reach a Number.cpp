class Solution {
public:
    int reachNumber(int target) {
        long long sum = 0;
        long long tar = target;
        for(int i = 1;;i++){
            sum += i;
            if(abs(tar) <= sum && !((sum - abs(tar))%2)) return i;
        }
    }
};
