// 641. Design Circular Deque
class MyCircularDeque {
private:
    vector<int> deque;
    int max_size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        max_size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(deque.size() == max_size)
            return false;
        deque.insert(deque.begin(), value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(deque.size() == max_size)
            return false;
        deque.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(deque.size() == 0)
            return false;
        deque.erase(deque.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(deque.size() == 0)
            return false;
        deque.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(deque.size() == 0)
            return -1;
        return deque[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(deque.size() == 0)
            return -1;
        int i = deque.size() - 1;
        return deque[i];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(deque.size() == 0)
            return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(deque.size() == max_size)
            return true;
        return false;
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