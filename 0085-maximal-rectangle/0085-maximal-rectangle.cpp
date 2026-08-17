class Solution {
private:
    // Next Smaller Element
    vector<int> nextsmallerElement(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            while (st.top() != -1 && arr[st.top()] >= arr[i]) {

                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Previous Smaller Element
    vector<int> prevsmallerElement(vector<int>& arr) {

        int n = arr.size();

        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            while (st.top() != -1 && arr[st.top()] >= arr[i]) {

                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> next = nextsmallerElement(heights);
        vector<int> prev = prevsmallerElement(heights);

        int area = 0;

        for (int i = 0; i < n; i++) {

            // If no smaller element on right
            if (next[i] == -1) {
                next[i] = n;
            }

            // Calculate width
            int width = next[i] - prev[i] - 1;

            // Calculate area
            int newArea = heights[i] * width;

            area = max(area, newArea);
        }

        return area;
    }

public:
    // Maximal Rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Empty matrix check
        if (matrix.empty()) {
            return 0;
        }

        int m = matrix.size();    // rows
        int n = matrix[0].size(); // columns

        // Histogram heights
        vector<int> heights(n, 0);

        int maxArea = 0;

        // Process every row
        for (int i = 0; i < m; i++) {

            // Convert current row into histogram
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == '1') {

                    heights[j]++;
                } else {

                    heights[j] = 0;
                }
            }

            // Find largest rectangle in current histogram
            int currentArea = largestRectangleArea(heights);

            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }
};