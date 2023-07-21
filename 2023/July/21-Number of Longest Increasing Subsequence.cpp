class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> mem(nums.size());

    pair<int, int> res{0, 0};
    for (int i = 0; i < nums.size(); ++i) {
      auto p = dfs(nums, mem, i);

      if (p.first > res.first) {
        res.first = p.first;
        res.second = p.second;
      } else if (p.first == res.first) {
        res.second += p.second;
      }
    }

    return res.second;
  }

  pair<int, int> dfs(vector<int>& nums,
                     vector<pair<int, int>>& mem,
                     int start) {
    if (mem[start].first > 0) {
      return mem[start];
    }

    pair<int, int> res{0, 1};

    for (int i = start + 1; i < nums.size(); ++i) {
      if (nums[i] > nums[start]) {
        auto p = dfs(nums, mem, i);

        if (p.first > res.first) {
          res.first = p.first;
          res.second = p.second;
        } else if (p.first == res.first) {
          res.second += p.second;
        }
      }
    }

    res.first += 1;

    mem[start] = res;

    return res;
  }
};
