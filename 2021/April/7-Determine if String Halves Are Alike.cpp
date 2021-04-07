class Solution {
public:
    bool halvesAreAlike(string s) {
        char vowel[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int a = 0, b = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<10;j++){
                if(s[i]==vowel[j]){
                    if(i < s.length() / 2) a++;
                    else b++;
                }
            }
        }
        return a==b;
    }
};
