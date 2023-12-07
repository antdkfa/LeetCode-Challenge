class Solution {
    public String largestGoodInteger(String num) {
        String ans = "";
        int val = -1;
        for(int i=0;i<num.length()-2;i++) {
            if(num.charAt(i) == num.charAt(i+1) && num.charAt(i) == num.charAt(i+2)) {
                String tmp = num.substring(i,i+3);
                if(val < num.charAt(i) - '0') {
                    val = num.charAt(i) - '0';
                    ans = tmp;
                }
            }
        }

        return ans;
    }
}
