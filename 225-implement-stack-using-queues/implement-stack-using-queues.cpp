class MyStack {
private:
    queue<int> q1;
public:
    MyStack() {}
    
    void push(int x) {
        int l=q1.size();
        q1.push(x);
        // int l=q1.size();
        while(l--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int deletedEle=q1.front();
        q1.pop();
        return deletedEle;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
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