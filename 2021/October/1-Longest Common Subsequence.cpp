class Solution {
public:
    int lcs(string text1, int len1, string text2, int len2, vector<vector<int>>& tab) {      
        for(int k = 0; k < len2+1; k++)
            tab[0][k] = 0;
        for(int k = 0; k < len1+1; k++)
            tab[k][0] = 0;
        
        for(int l1 = 1; l1 < len1+1; l1++) {
            for(int l2 = 1; l2 < len2+1; l2++) {
                if(text1[l1-1] == text2[l2-1]) 
                    tab[l1][l2] = 1 + tab[l1-1][l2-1];
                else
                    tab[l1][l2] = max(tab[l1][l2-1],tab[l1-1][l2]);
            }
        }
        
        return tab[len1][len2];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        
        vector<vector<int>> tab(len1 + 1,vector<int>(len2 + 1,-1));
        
        return lcs(text1,len1,text2,len2,tab);
    }
};
