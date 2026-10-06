class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        stack<int> st;
        int second = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {

            // nums[i] = 1 candidate
            if (nums[i] < second) {
                return true;
            }

            // popped elements = possible 2
            while (!st.empty() && nums[i] > st.top()) {
                second = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};