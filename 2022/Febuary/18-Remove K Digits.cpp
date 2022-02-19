class Solution {
public:
    int cnt = 0;
    
    string updateRegularForm(string num) {
        bool flag = false;
        string ret = "";
        for(int i=0;i<num.size();i++) {
            if(num[i] == '0' && !flag) {
                continue;
            } else {
                flag = true;
                ret += num[i];
            }
        }
        return ret == "" ? "0" : ret;
    }
    
    string removeBiggerFront(string num) {
        deque<char> d;
        d.push_front(num[0]);
        for(int i=1;i<num.size();i++) {
            if(!cnt) d.push_back(num[i]);
            else {
                while(cnt && !d.empty()) {
                    if(num[i]< d.back()){
                        d.pop_back();
                        cnt--;
                    } else break;
                }
                d.push_back(num[i]);
            }
        }
        
        string ret = "";
        for(int i=0;i<d.size();i++) {
            ret += d[i];
        }
        return ret;
    } 
    
    string removeKdigits(string num, int k) {
        cnt = k;
        string removedBiggerFront = removeBiggerFront(num);
        string regularForm = updateRegularForm(removedBiggerFront);
        
        if(regularForm.size() < cnt) return "0";
        
        string ans = "";
        for(int i=0;i<regularForm.size() - cnt;i++) {
            ans += regularForm[i];
        }
        return ans == "" ? "0" : ans;
    }
};
