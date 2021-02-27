class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
          stack<int> st;
        int n=pushed.size();
        int m=popped.size();
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(pushed[i]!=popped[j])
            {
                st.push(pushed[i]);
            }
            else
            {
                j++;
                while(st.size()>0 and st.top()==popped[j])
                {
                    st.pop();
                    j++;
                }
            }
        }
        
		// if we return st.empty() here then also it would be correct
		// returning st.empty() here decreasing the runtime of the code as we have one extra while loop written at the end
		
        while(j<m)   // instead of this loop we can just check whether our stack is empty or not
        {
            if(st.top()!=popped[j])
                return false;
            else
                j++;
        }
        return true;
    }
};
