// Link: https://leetcode.com/problems/design-circular-deque/description/

class MyCircularDeque {
public:

    int queue[1001];
    int k, front, back, len;

    MyCircularDeque(int k) : k(k), front(0), back(k-1), len(0) {
        
    }
    
    bool insertFront(int value) {
        if (len == k) return false;
        front = (front == 0) ? k - 1 : front - 1;
        queue[front] = value;
        len++;
        return true;
    }
    
    bool insertLast(int value) {
        if (len == k) return false;
        back = (back == k-1) ? 0 : back + 1;
        queue[back] = value;
        len++;
        return true;
    }
    
    bool deleteFront() {
        if (len == 0) return false;
        front = (front == k - 1) ? 0 : front + 1;
        len--;
        return true;
    }
    
    bool deleteLast() {
        if (len == 0) return false;
        back = (back == 0) ? k - 1 : back - 1;
        len--;
        return true;
    }
    
    int getFront() {
        return (len == 0) ? -1 : queue[front];
    }
    
    int getRear() {
        return (len == 0) ? -1 : queue[back];
    }
    
    bool isEmpty() {
        return len == 0;
    }
    
    bool isFull() {
        return len == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
