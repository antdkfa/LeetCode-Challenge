class Solution {
    int converter(char c) {
        if(c == 'M') return 0;
        else if(c == 'P') return 1;
        return 2;
    }

    public int garbageCollection(String[] garbage, int[] travel) {
        int[] total = new int[3];
        for(String s: garbage) {
            for(int i=0;i<s.length();i++) {
                int convert = converter(s.charAt(i));
                total[convert]++;
            }
        }

        int ans = 0;
        int[] sum = new int[3];
        for(int i=0;i<garbage.length;i++) {
            ans += garbage[i].length();
             for(int j=0;j<garbage[i].length();j++) {
                int convert = converter(garbage[i].charAt(j));
                total[convert]--;
             }
             if(total[0] != 0) ans += travel[i];
             if(total[1] != 0) ans += travel[i];
             if(total[2] != 0) ans += travel[i];
        }

        return ans;
    }
}
