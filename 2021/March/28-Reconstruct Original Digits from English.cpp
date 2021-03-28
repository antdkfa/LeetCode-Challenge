class Solution {
public:
    
    vector<string> tmp;
    int alpha[30] = {0,}, zero, one, two, three, four, five, six, seven, eight, nine;
        
    void find(string a, string b, int c){
        for(int i=0;i<c;i++) tmp.push_back(b);
        for(int i=0;i<a.length();i++){
            alpha[a[i]-'a'] -= c;
        }
    }
    
    string originalDigits(string s) {
        string ans="";
        for(int i=0;i<s.length();i++) alpha[s[i]-'a']++;
        
        zero = alpha['z'-'a'];
        find("zero","0",zero);
        
        four = alpha['u'-'a'];
        find("four","4",four);
        
        five = alpha['f'-'a'];
        find("five","5",five);
        
        six = alpha['x'-'a'];
        find("six","6",six);
        
        seven = alpha['s'-'a'];
        find("seven","7",seven);
        
        eight = alpha['g'-'a'];
        find("eight","8", eight);
        
        nine = alpha['i'-'a'];
        find("nine","9",nine);
        
        three = alpha['r'-'a'];
        find("three","3",three);
        
        two = alpha['t'-'a'];
        find("two","2",two);
        
        one = alpha['o'-'a'];
        find("one", "1", one);
        
        sort(tmp.begin(), tmp.end());
        for(int i=0;i<tmp.size();i++) ans+=tmp[i];
        
        return ans;
    }
};
