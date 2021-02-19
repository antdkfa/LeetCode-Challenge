class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans ="";
        int op=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                op++;   
            }
            else if(s[i]==')'){
                op--;
                if(op<0)op=0,s[i]='*';
            }
        }
        if(op>0){
            for(int i=s.length()-1;i>=0;i--){
                if(s[i]=='(')s[i]='*',op--;
                if(!op)break;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!='*')ans+=s[i];
        }
        return ans;
    }
};
