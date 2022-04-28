class Solution {
public:
    
    int find(int mid, vector<vector<int>> heights){
        int fr[4]={1,0,-1,0},fc[4]={0,1,0,-1}, n=heights.size(),m=heights[0].size();
        typedef pair<int,int>p;
        int visited[105][105]={0,};
        queue<p>q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            if(r==n-1&&c==m-1) return 1;
            for(int i=0;i<4;i++){
                int nr=r+fr[i],nc=c+fc[i];
                if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]||abs(heights[r][c]-heights[nr][nc])>mid) continue;
                else{
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return 0;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans;
        int s=0,e=1000000;
        while(s<=e){
            int mid=(s+e)/2;
            if(find(mid,heights)) ans=mid,e=mid-1;
            else s=mid+1;
        }
        return ans;
    }
};
