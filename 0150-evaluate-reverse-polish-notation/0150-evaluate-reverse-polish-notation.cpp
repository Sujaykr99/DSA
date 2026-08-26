class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" &&
                tokens[i] != "*") {

                st.push(stoi(tokens[i]));

            } else {

                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                if (tokens[i] == "+") {

                    st.push(x + y);
                }

                else if (tokens[i] == "-") {
                    st.push(y - x);
                }

                else if (tokens[i] == "*") {

                    st.push(x * y);
                }

                else if (tokens[i] == "/") {

                    int divide = y / x;
                    st.push(divide);
                }
            }
        }

        return st.top();
    }
};