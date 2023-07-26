class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1, e = 10000000;
        int ans = -1;
        while(s<=e) {
            int speed = (s+e)/2;
            double nowHour = 0;
            for(int i=0;i<dist.size() - 1;i++) {
                nowHour += ceil((double)dist[i]/speed);
            }
            nowHour += (double)dist[dist.size()-1]/speed;
            if(nowHour <= hour) {
                ans = speed;
                e = speed-1;
            } else s = speed+1;
        }
        return ans;
    }
};
