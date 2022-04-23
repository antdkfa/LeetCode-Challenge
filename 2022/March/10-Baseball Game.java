class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> s = new Stack<>();
        for(String op: ops) {
            if(op.equals("C")) {
                s.pop();
            } else if(op.equals("D")) {
                s.push(s.peek()*2);
            } else if(op.equals("+")) {
                int a = s.pop();
                int b = s.pop();
                s.push(b);
                s.push(a);
                s.push(a+b);
            } else {
                s.push(Integer.parseInt(op));
            }
        }
        int ans = 0;
        while(!s.isEmpty()) {
            ans += s.pop();
        }
        return ans;
    }
}
