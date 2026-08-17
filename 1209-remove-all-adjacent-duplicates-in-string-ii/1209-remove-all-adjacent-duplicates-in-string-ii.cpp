class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (st.empty()) {
                st.push({ch, 1});
            } else if (st.top().first == ch) {

                st.top().second++;

                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({ch, 1});
            }
        }

        string ans = "";
        while (!st.empty()) {

            char ch = st.top().first;
            int count = st.top().second;

            while (count--) {
                ans.push_back(ch);
            }

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};