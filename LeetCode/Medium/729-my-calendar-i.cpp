// Link: https://leetcode.com/problems/my-calendar-i/description/

class MyCalendar {
public:

    vector<pair<int, int>> events;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for (const auto& event : events) {
            int bookedStart = event.first;
            int bookedEnd = event.second;
            
            if (start < bookedEnd && end > bookedStart) {
                return false;
            }
        }
        
        events.push_back({start, end});
        return true;

    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
