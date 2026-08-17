// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {

//         vector<int>ans ;

//         for(int i = 0 ; i < nums.size() ; i++){

//             bool found = false ;

//               for(int j = 1 ; j < nums.size() ; j++){

//                 int index = (i + j) % nums.size() ;

//                    if(nums[index]>nums[i]){

//                     ans.push_back(nums[index]) ;
//                     found = true ;
//                     break ;
//                    }
//               }

//             if(found== false){
//                 ans.push_back(-1) ;
//             }
//         }
//     return ans ;

//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //  2n iterations
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {

            int index = i % n;

            while (!st.empty() && st.top() <= nums[index]) {

                st.pop();
            }
            if (i < n) {
                if (st.empty()) {
                    ans[index] = -1;

                } else {
                    ans[index] = st.top();
                }
            }

            st.push(nums[index]);
        }

        return ans;
    }
};