class MinStack {
public:
stack<int>s;
        stack<int>minstack;//keep another stack to store min value
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minstack.empty())
        minstack.push(val);
        else
        minstack.push(min(minstack.top(),val));//always store minimum value at the top
    }
    
    void pop() {
        minstack.pop();//since we are calculating minimum, we keep track of min and therefore popping is similar 
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
//tc= o(1) for each function
