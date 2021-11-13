class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
      stack<pair<int,int>> s;  
      int len=t.size();  
      if(len==1)
          return {0};
      vector<int> ans(len);    
      s.push({len-1,t[len-1]}); 
        
      for(int i=len-2;i>=0;i--)
      {
          if(t[i]<s.top().second)
              ans[i]=s.top().first-i;
          else{        
              while(!s.empty()&&t[i]>=s.top().second)
                  s.pop();
              if(s.empty()){  
                  ans[i]=0;
                  s.push({i,t[i]});
                  continue;
              }
              else
                  ans[i]=s.top().first-i;     
   
          }
          s.push({i,t[i]});
      }
        
        return ans;
    }
};
