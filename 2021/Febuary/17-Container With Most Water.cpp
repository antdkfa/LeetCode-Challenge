class Solution {
public:
    int maxArea(vector<int>& height) {
                
        int i,n=height.size();
        
        //firstLeft[i] is the index of height >= height[i] and to the left as possible
        //firstRight[i] is the index of height >= height[i] and to the right as possible
        
        vector<int>firstLeft(3e4+2,n+1);
        vector<int>firstRight(3e4+2,-1);
        
        
        
        for(i=0;i<n;i++)
        {
            firstLeft[height[i]]=min(firstLeft[height[i]],i);
        }
        
        for(i=n-1;i>=0;i--)
        {
            firstRight[height[i]]=max(firstRight[height[i]],i);
        }
        
        for(i=3e4;i>=1;i--)
        {
            firstLeft[i]=min(firstLeft[i],firstLeft[i+1]);
            firstRight[i]=max(firstRight[i],firstRight[i+1]);
        }
        
        
        int ans=0;
        for(i=0;i<n;i++)
        {
            int l=firstLeft[height[i]];
            int r=firstRight[height[i]];
            if(l<i)ans=max(ans,(i-l)*height[i]);
            if(i<r)ans=max(ans,(r-i)*height[i]);
        }
        return ans;
    }
};
