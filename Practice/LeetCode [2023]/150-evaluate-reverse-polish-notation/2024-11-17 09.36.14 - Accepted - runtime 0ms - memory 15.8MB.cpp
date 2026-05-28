class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s; 
        for (const string& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                if (c == "+") s.push(a + b);
                else if (c == "-") s.push(a - b);
                else if (c == "*") s.push(a * b);
                else if (c == "/") s.push(a / b);
            } else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
