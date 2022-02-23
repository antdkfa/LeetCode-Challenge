/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    HashMap<Integer,Node> map = new HashMap<>();
    int[][] visited = new int[105][105];
    Node ans = new Node();
    
    public int dfs(Node org, Node clone) {
        for(int i=0;i<org.neighbors.size();i++) {
            int next = org.neighbors.get(i).val;
            if(visited[org.val][next] == 0 || visited[next][org.val] == 0) {
                visited[org.val][next] = 1;
                visited[next][org.val] = 1;
                
                Node nextNode;
                if(map.get(next) != null) nextNode = map.get(next);
                else {
                    nextNode = new Node(next);
                    map.put(nextNode.val, nextNode);
                }
                
                clone.neighbors.add(nextNode);
                nextNode.neighbors.add(clone);
                dfs(org.neighbors.get(i), nextNode);
            }
        }
        return 0;
    }
    
    public Node cloneGraph(Node node) {
        if(node == null) return null;
        ans.val = node.val;
        map.put(1,ans);
        dfs(node,ans);
        return ans;
    }
}
