class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if(!asteroids.size() || asteroids.size() == 1) return asteroids;
        stack<int> s;
        vector<int> v;
        s.push(asteroids[0]);
        for(int i = 1;i< asteroids.size();i++){
            if(asteroids[i] < 0){
                if(s.empty()) s.push(asteroids[i]);
                else {
                    while(!s.empty()){
                        int before = s.top();
                        if(before > 0) {
                            if(before > abs(asteroids[i])){
                                break;
                            }
                            else if(before < abs(asteroids[i])){
                                s.pop();
                            }
                            else{
                                s.pop();
                                break;
                            }
                        }
                        else {
                            s.push(asteroids[i]);
                            break;
                        }
                        if(s.empty()) {
                            s.push(asteroids[i]);
                            break;
                        }
                    }   
                }
            }
            else s.push(asteroids[i]);
        }
        while(!s.empty()){
            int now = s.top();
            s.pop();
            v.push_back(now);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
