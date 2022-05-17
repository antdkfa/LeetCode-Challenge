class Solution {
    private class Pair {
        int r;
        int c;
        int depth;
        Pair(int r, int c, int depth) {
            this.r = r;
            this.c = c;
            this.depth = depth;
        }
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid[0][0] == 1) return -1;
        Queue<Pair> q = new LinkedList<>();
        int[][] visited = new int[grid.length][grid[0].length];
        int[] fr = {-1,1,0,0,-1,-1,1,1};
        int[] fc = {0,0,-1,1,-1,1,-1,1};
        visited[0][0] = 1;
        q.add(new Pair(0, 0, 1));
        while(!q.isEmpty()) {
            Pair now = q.poll();
            if(now.r == grid.length - 1 && now.c == grid[0].length - 1) return now.depth;
            for(int i=0;i<8;i++) {
                int nr = now.r + fr[i];
                int nc = now.c + fc[i];
                if(nr < 0 || nr >= grid.length || nc < 0 || nc >= grid[0].length || visited[nr][nc] == 1 || grid[nr][nc] == 1) continue;
                visited[nr][nc] = 1;
                q.add(new Pair(nr, nc, now.depth + 1));
            }
        }
        return -1;
    }
}
