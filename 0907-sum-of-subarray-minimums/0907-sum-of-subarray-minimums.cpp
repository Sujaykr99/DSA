class Solution {

private:

    vector<int> prevSmaller(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }


    vector<int> nextSmaller(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            }
            else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }


public:

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> left = prevSmaller(arr);
        vector<int> right = nextSmaller(arr);

        long long MOD = 1000000007;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            long long contribution =
                arr[i] * leftCount * rightCount;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};