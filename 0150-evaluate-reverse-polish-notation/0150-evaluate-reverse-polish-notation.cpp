class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto a : tokens) {
            if (a.size() == 1 && !isdigit(a[0])) {  // check if an operator
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                switch (a[0]) {  // note switch use char or integer
                    case '+':
                        s.push(num1 + num2);
                        break;
                    case '-':
                        s.push(num1 - num2);
                        break;
                    case '*':
                        s.push(num1 * num2);
                        break;
                    case '/':
                        s.push(num1 / num2);
                        break;
                }
            } else {  // if an number push to stack
                s.push(atoi(a.c_str()));
            }
        }
        return s.top();
    }
};