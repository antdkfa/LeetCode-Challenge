class Solution {
public:
    int n[5] = {0, }, idx=0;
    string ans = "";
    void make(int idx, string a, string b, char c, char d) {
        if(n[idx] == 4) ans += a;    
        else if (n[idx] == 9) ans += b;
        else {
            if(n[idx]>=5) ans+=c, n[idx]-=5;
            for(int i=0;i<n[idx];i++) ans+=d;
        }
    }
    string intToRoman(int num) {
        while(num){
            n[idx++] += num%10;
            num /= 10;
        }
        for(int i=0;i<n[3];i++) ans+='M';
        make(2,"CD","CM",'D','C');
        make(1,"XL","XC",'L','X');
        make(0,"IV","IX",'V','I');
        return ans;
    }
};
