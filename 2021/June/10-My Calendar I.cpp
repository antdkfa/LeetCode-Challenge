class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if(v[i].second <= start || end <= v[i].first) continue;
            else return false;
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
