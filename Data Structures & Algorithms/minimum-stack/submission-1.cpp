class MinStack {
public:
    deque<int> myData {};
    deque<int> minItem {};
    MinStack() {   
    }    
    void push(int val) {
        myData.push_front(val);
        if (minItem.size() != 0 && (val <= minItem.front())) {
            minItem.push_front(val);
        } else if (minItem.size() == 0){
            minItem.push_front(val);
        }
    }
    
    void pop() {
        if (myData.front() == minItem.front()) {
            minItem.pop_front();
        }
        myData.pop_front();
    }
    
    int top() {
        return myData.front();
    }
    
    int getMin() {
        return minItem.front();
    }
};
