class Solution {
  public:
      string removeDuplicateLetters(string text)
      {
          int last[26] = {};
          int seen[26] = {};
          int n = (int)text.size();
          string ans="";
          for(int i=0;i<n;i++)
              last[text[i]-'a'] = i; // In order to know the last occurence of a character(step 2 above).At any point if we want to know that a given character is available in the future iterations.
          
          for(int i=0;i<n;i++)
          {
              if(seen[text[i]-'a'])
                  continue;
              seen[text[i]-'a']++; // To avoid adding duplicates
              while(!ans.empty() and ans.back()>text[i] and i<last[ans.back()-'a']) // As explained in step 2 above.
              {
                  seen[ans.back()-'a'] = 0; // We have to reset this character in seen to 0 because when it comes again in future, it has to be added to the answer again.
                  ans.pop_back();
              }
              
              ans.push_back(text[i]);
          }
          return ans;
      }
};
