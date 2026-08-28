class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        int right = 0;
        int left = 0;

        int minlen = INT_MAX;
        int sindex = -1;
        int cnt = 0;

        int mpp[256] = {};

        if (t.empty()) return "";

        for (int i = 0; i < m; i++) {
            mpp[t[i]]++;
        }

        while (right < s.size()) {

            if (mpp[s[right]] > 0) {
                cnt++;
            }

            mpp[s[right]]--;

            while (cnt == m) {

                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    sindex = left;
                }

         
                if (mpp[s[left]] == 0) {
                    cnt--;
                }

               
                mpp[s[left]]++;

                left++;
            }

            right++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};