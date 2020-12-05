class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for(int i = 0;i<flowerbed.size();i++){
            if(!flowerbed[i]){
                int l = max(i - 1, 0), r = min(i + 1, (int)flowerbed.size() - 1);
                if(!flowerbed[l] && !flowerbed[r]) cnt++,i++;
            }
        }
        if(cnt >= n) return true;
        return false;
    }
};
