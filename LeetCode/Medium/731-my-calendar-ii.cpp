// Link: https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo {
public:

    map <int, int> bookings;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {

        bookings[start]++;
        bookings[end]--;

        int active = 0;

        for (auto &[time, count] : bookings){
            active += count;

            if (active >= 3){
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }

        return true;

    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
