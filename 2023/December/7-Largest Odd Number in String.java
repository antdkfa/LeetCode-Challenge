class Solution {
    public String largestOddNumber(String num) {
        String ans = "";
        int oddIdx = -1;
        for(int i=num.length()-1;i>=0;i--) {
            final var a = num.charAt(i) - '0';
            if(a%2 != 0) {
                oddIdx = i;
                break;
            }
        }

        for(int i=0;i<=oddIdx;i++) {
            ans += num.charAt(i);
        }
        return ans;
    }
}
