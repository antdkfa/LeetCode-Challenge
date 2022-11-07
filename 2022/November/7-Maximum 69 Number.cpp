class Solution {
public:
    int maximum69Number (int num) {
        string now = "";
        while(num) {
            now += num % 10 + '0';
            num /= 10;
        }
        reverse(now.begin(), now.end());
        for(int i=0;i<now.length();i++) {
            if(now[i] == '6') {
                now[i] = '9';
                break;
            }
        }
        
        return stoi(now);
    }
};
