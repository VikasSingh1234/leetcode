class MyStack {
    queue<int> Q1,Q2;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        Q2.push(x);
        
        while(!Q1.empty()){
            int t = Q1.front();
            Q1.pop();
            Q2.push(t);
        }
        
        while(!Q2.empty()){
            int t = Q2.front();
            Q2.pop();
            Q1.push(t);
        }
    }
    
    int pop() {
        if(!Q1.empty()){
            int t = Q1.front();
            Q1.pop();
            return t;
        }
        return -1;
    }
    
    int top() {
        if(!Q1.empty()){
            int t = Q1.front();
            return t;
        }
        return -1;
    }
    
    bool empty() {
        if(Q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */