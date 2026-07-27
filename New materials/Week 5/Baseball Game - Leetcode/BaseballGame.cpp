class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(int i = 0; i < operations.size(); ++i) {

            if(operations[i] == "C") {
                st.pop();
            }
            else if(operations[i] == "D") {
                int previous = st.top();
                st.push(previous * 2);
            }
            else if(operations[i] == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            }
            else {
                st.push(stoi(operations[i]));
            }
        }


        int result = 0;

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
