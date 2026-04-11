class MinStack {
public:
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        minst.push(val);
    }
    
    void pop() {
        minst.pop();
    }
    
    int top() {
        return minst.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int minS = minst.top();
        while(!minst.empty()) {
            minS = min(minS, minst.top());
            tmp.push(minst.top());
            minst.pop();
        }

        while(!tmp.empty()) {
            minst.push(tmp.top());
            tmp.pop();
        }

        return minS;
    }
};
