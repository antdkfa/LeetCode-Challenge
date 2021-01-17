class Solution {
public:
  int countVowelStrings(int n) {
    vector<int64_t> cnt(5, 1);
    for (int i = 1; i < n; i++)
      for (int j = 3; j >= 0; j--) cnt[j] += cnt[j + 1];
    return accumulate(cnt.begin(), cnt.end(), 0);
  }
};
