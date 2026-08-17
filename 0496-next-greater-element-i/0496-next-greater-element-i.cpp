
// // brute - force version
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

//         vector<int> ans;

//         for (int i = 0; i < nums1.size(); i++) {

//             for (int j = 0; j < nums2.size(); j++) {

//                 if (nums1[i] == nums2[j]) {

//                     int found = false;

//                     for (int k = j + 1; k < nums2.size(); k++) {

//                         if (nums2[k] > nums1[i]) {

//                             ans.push_back(nums2[k]);
//                             found = true;
//                             break;
//                         }
//                     }
//                     if (found == false) {
//                         ans.push_back(-1);
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mpp;

        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums2[i]) {

                st.pop();
            }

            if (st.empty()) {
                mpp[nums2[i]] = -1;
            } else {
                mpp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> greater;

        for (int i = 0; i < nums1.size(); i++) {
            greater.push_back(mpp[nums1[i]]);
        }
        return greater;
    }
};