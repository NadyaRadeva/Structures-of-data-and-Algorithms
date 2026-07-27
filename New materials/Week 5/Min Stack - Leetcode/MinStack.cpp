class MinStack {
public:
vector<int> arr;
vector<int> min;

    MinStack() {
        
    }
    
    void push(int value) {
        arr.push_back(value);

        if(min.empty()) {
            min.push_back(value);
        }
        else {
            min.push_back(min.back() > value ? value : min.back());
        }
    }
    
    void pop() {
        arr.pop_back();
        min.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
