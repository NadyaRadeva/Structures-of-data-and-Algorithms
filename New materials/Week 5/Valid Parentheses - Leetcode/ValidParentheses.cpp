class Solution {
public:
    bool isOpening(char ch) {
        return ch == '{' || ch == '(' || ch == '[';
    }

    bool isReversed(char l, char r) {
        return (l == '{' && r == '}') || (l == '(' && r == ')') || (l == '[' && r == ']');
    }

    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); ++i) {
            if(isOpening(s[i])) {
                st.push(s[i]);
            }
            else {
                if(st.empty() || !isReversed(st.top(), s[i])) {
                    return false;
                }

                st.pop();
            }
        }

        return st.size() == 0;
    }
};
