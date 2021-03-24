class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<A.size();i++) s.insert(A[i]);
        for(int i=0;i<B.size();i++){
            auto it = s.upper_bound(B[i]);
            if(it == s.end()) it = s.lower_bound(0);
            v.push_back(*it);
            s.erase(it);
        }
        return v;
    }
};
