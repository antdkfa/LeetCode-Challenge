class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        char ch[5] = {'V','L','D','M'};
        int val[5] = {5,50,500,1000};
        s+='.';
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V') ans+=4,i++;
                else if(s[i+1]=='X') ans+=9,i++;
                else ans+=1;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L') ans+=40,i++;
                else if(s[i+1]=='C') ans+=90,i++;
                else ans+=10;
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D') ans+=400,i++;
                else if(s[i+1]=='M') ans+=900,i++;
                else ans+=100;
            }
            else {
                for(int j=0;j<4;j++){
                    if(s[i]==ch[j]) ans+=val[j];
                }
            }
        }
        return ans;
    }
};
