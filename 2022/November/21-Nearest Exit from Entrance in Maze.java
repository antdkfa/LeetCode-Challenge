class Solution {
    class Pair {
        int r;
        int c;
        int depth;
        
        public Pair(int r, int c, int depth) {
            this.r = r;
            this.c= c;
            this.depth = depth;
        }
    }
    
    public int nearestExit(char[][] maze, int[] entrance) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(entrance[0], entrance[1], 0));
        maze[entrance[0]][entrance[1]] = '+';
        int[] fr= {1,-1,0,0};
        int[] fc = {0,0,-1,1};
        while(!q.isEmpty()) {
            Pair now = q.poll();
            if((now.r == 0 || now.c == 0 || now.r == maze.length - 1 || now.c == maze[0].length - 1) && (now.r != entrance[0] || now.c != entrance[1])) return now.depth;
            for(int i=0;i<4;i++) {
                int nr = now.r + fr[i], nc = now.c + fc[i];
                if(nr < 0 || nc < 0 || nr >= maze.length || nc >= maze[0].length || maze[nr][nc] == '+') continue;
                maze[nr][nc] = '+';
                q.add(new Pair(nr,nc,now.depth+1));
            }
        }
        return -1;
    }
}
