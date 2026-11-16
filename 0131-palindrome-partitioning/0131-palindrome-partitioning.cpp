class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

public:
    void solve(string s, int idx, vector<vector<string>>& ans,
               vector<string>& temp) {

        // base case
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx ; i < s.size(); i++) {

            string substring = s.substr(idx, i - idx + 1);

            // check palindrome
            if (isPalindrome(s, idx, i)) {
                temp.push_back(substring);

                solve(s, i + 1, ans, temp) ;

                temp.pop_back() ;
            }

          
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, ans, temp);

        return ans;
    }
};