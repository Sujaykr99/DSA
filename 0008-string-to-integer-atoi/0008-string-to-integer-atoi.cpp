class Solution {
private:
    void solve(string &s, int idx, long long &result) {

        // Base case
        if (idx >= s.length() || !isdigit(s[idx])) {
            return;
        }

        int digit = s[idx] - '0';

        // Overflow check
        if (result > (INT_MAX - digit) / 10) {
            result = (long long)INT_MAX + 1;
            return;
        }

        result = result * 10 + digit;

        solve(s, idx + 1, result);
    }

public:
    int myAtoi(string s) {

        int i = 0;

        // Skip leading spaces
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check sign
        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long result = 0;

        solve(s, i, result);

        result *= sign;

        if (result > INT_MAX)
            return INT_MAX;

        if (result < INT_MIN)
            return INT_MIN;

        return (int)result;
    }
};