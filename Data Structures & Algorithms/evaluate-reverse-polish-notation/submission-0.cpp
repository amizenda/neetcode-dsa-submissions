class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> notation;

        for(string& x : tokens) {
            if(x == "+" || x == "-" || x == "*" || x == "/") {
                int b = notation.top(); notation.pop();
                int a = notation.top(); notation.pop();
                
                if (x == "+") notation.push(a + b);
                else if (x == "*") notation.push(a * b);
                else if (x == "-") notation.push(a - b);
                else if (x == "/") notation.push(a / b);
            } else {
                notation.push(stoi(x));
            }
        }

        return notation.top();
    }
};
