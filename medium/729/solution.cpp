class MyCalendar {
public:
    std::vector<std::pair<int,int>> events;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for (auto const& e : events){
            if(start < e.second && end > e.first){
                return false;
            }
        }
        std::pair<int,int> new_event;
        new_event.first = start;
        new_event.second = end;
        events.push_back(new_event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
