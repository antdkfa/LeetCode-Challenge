class Solution {
    public int titleToNumber(String columnTitle) {
        int ans=0;
        for(int i=columnTitle.length()-1,j=1;i>=0;i--,j*=26) {
            ans += (columnTitle.charAt(i)-'A'+1)*j;
        }
        return ans;
    }
}
