class Solution {
public:
    int addition(int a, int b) {
        return a + b;
    }

    int subtraction(int a, int b) {
        return a - b;
    }

    int multiplication(int a, int b) {
        return a * b;
    }

    int division(int a, int b) {
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> result;

        for(int i = 0; i < tokens.size(); ++i) {

            if(tokens[i] == "+") {
                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                result.push(addition(a, b));
            }

            else if(tokens[i] == "-") {
                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                result.push(subtraction(a, b));
            }

            else if(tokens[i] == "*") {
                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                result.push(multiplication(a, b));
            }

            else if(tokens[i] == "/") {
                int b = result.top();
                result.pop();

                int a = result.top();
                result.pop();

                result.push(division(a, b));
            }

            else {
                result.push(stoi(tokens[i]));
            }
        }

        return result.top();
    }
};
