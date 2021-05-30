class Solution {
public:
    int ans = 0;
    string num = "";
    void go(int depth, vector<string> digits) {
        if(depth == num.length()) { ans++; return; }
        for(int i = 0;i<digits.size();i++){
            if(digits[i][0] < num[depth]) ans += pow(digits.size(), num.length() - (depth + 1));
            else if(digits[i][0] == num[depth]) go(depth + 1, digits);
            else break;
        }
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        while(n) {
            num += (n % 10) + '0';
            n /= 10;
        }
        reverse(num.begin(), num.end());
        go(0, digits);
        for(int i = 1;i<num.length();i++){
            ans += pow(digits.size(), i);
        }
        return ans;
    }
};
