class Solution {
    ArrayList<Integer> ans = new ArrayList<>();
    Queue<Pair> q = new LinkedList<>();
    public class Pair {
        String first;
        int second;
        public Pair(String first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public void bfs(int low,int high) {
        while(!q.isEmpty()) {
            String now = q.peek().first;
            int second = q.peek().second;
            int nowInt = Integer.parseInt(now);
            q.poll();
            if(now.length() == 10) break;
            if(low <= nowInt && nowInt <= high) ans.add(nowInt);
            if(second != 9) {
                String next = now + (char)((second + 1) + '0');
                q.add(new Pair(next, second + 1));
            }
        }
    }
    
    public List<Integer> sequentialDigits(int low, int high) {
        ArrayList<Integer> list = new ArrayList<>();
        String start = "";
        for(int i=1;i<10;i++) q.add(new Pair(start + (char)(i+'0'), i));
        bfs(low, high);
        return ans;
    }
}
