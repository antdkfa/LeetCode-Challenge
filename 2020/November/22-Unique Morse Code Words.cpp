class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<string, int> m;
        int ans = 0;
        string t[30] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i = 0;i<words.size();i++){
            string tmp = "";
            for(int j = 0;j<words[i].length();j++){
                tmp += t[words[i][j] - 'a'];
            }
            if(!m[tmp]) m[tmp] = 1, ans++;
        }
        return ans;
    }
};
