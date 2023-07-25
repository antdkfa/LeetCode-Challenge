class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++) {
            int now = asteroids[i];
            if(s.empty()) {
                s.push(now);
            } else {
                int top = s.top();
                if(top<0) {
                    s.push(now);
                } else {
                    if(now>0) {
                        s.push(now);
                    } else {
                        // top > 0, now < 0
                        bool pushNow = false;
                        while(!s.empty() && s.top() > 0) {
                            if(s.top() < abs(now)) {
                                s.pop();
                                pushNow=true;
                            } else if(s.top() == abs(now)) {
                                s.pop();
                                pushNow=false;
                                break;
                            } else {
                                pushNow=false;
                                break;
                            }
                        }
                        if(pushNow) s.push(now);
                    }
                }
            }
        }
        
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
