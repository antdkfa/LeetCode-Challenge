class Solution {
public:

    int uniqueMorseRepresentations(vector<string>& words) {
        map<string,int> m;
        string trans[30] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int ans = 0;
        for(int i=0;i<words.size();i++) {
            string now = "";
            for(int j=0;j<words[i].length();j++) {
                now += trans[words[i][j] - 'a'];               
            }
            if(!m[now]) {
                m[now] = 1;
                ans++;
            }
        }
        
        return ans;
    }
};
