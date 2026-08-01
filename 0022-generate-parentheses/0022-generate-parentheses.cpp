class Solution {
private:
    void solve(int n, int open, int close, string output, vector<string>& s) {
        if (n == 0)
            return;

        // base case
        if (open == 0 && close == 0) {

            s.push_back(output);
            return;
        }

        if (open > 0) {
            output.push_back('(');
            solve(n, open - 1, close, output, s);
            output.pop_back();
        }
        if (close > open) {
            output.push_back(')');
            solve(n, open, close - 1, output, s);
            output.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> s;
        string output;

        int open = n;
        int close = n;
        solve(n, open, close, output, s);
        return s ;
    }
};