class Solution {
    class Pair implements Comparable<Pair> {
        private int first;
        private int second;
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
        
        @Override
        public int compareTo(Pair pair) {
            if(pair.second < second) return 1;
            else if(pair.second > second) return -1;
            else return 0;
        }
    }
    
    public int findMinArrowShots(int[][] points) {
        ArrayList<Pair> list = new ArrayList<>();
        for(int i=0;i<points.length;i++) {
            list.add(new Pair(points[i][0],points[i][1]));
        }
        Collections.sort(list);
        int shot = list.get(0).second, ans = 1;
        for(Pair pair: list) {
            if(pair.first <= shot && shot <= pair.second) continue;
            else {
                shot = pair.second;
                ans++;
            }
        }
        return ans;
    }
}
