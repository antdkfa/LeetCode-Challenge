class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans=0, visited[10005] = {0, };
        vector<int> sorted_nums;
        for(int i=0;i<nums.size();i++) sorted_nums.push_back(nums[i]);
        sort(sorted_nums.begin(),sorted_nums.end());
        for(int i=0;i<nums.size();i++){
            if(sorted_nums[i]!=nums[i]){
                break;
            }
            else visited[i]=1;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(sorted_nums[i]!=nums[i]){
                break;
            }
            else visited[i]=1;
        }
        for(int i=0;i<nums.size();i++) if(!visited[i]) ans++;
        return ans;
    }
};
