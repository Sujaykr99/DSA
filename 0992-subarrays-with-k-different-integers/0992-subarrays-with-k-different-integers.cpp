// TLE
/* int count = 0;
     int n = nums.size();

     for (int i = 0; i < n; i++) {

         map<int, int> mpp;

         for (int j = i; j < n; j++) {

             mpp[nums[j]]++;

             if (mpp.size() == k) {
                 count++;
             }

             if (mpp.size() > k) {
                 break;
             }
         }
     }

     return count; */

class Solution {
private:
    int atmostk(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        map<int, int> mpp;

        while (right < nums.size()) {
            mpp[nums[right]]++;

            while (mpp.size() >  k) {

                mpp[nums[left]]--;

                if (mpp[nums[left]] == 0) {
                   mpp.erase(nums[left]);
                }
                left++ ;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmostk(nums, k) - atmostk(nums, k - 1);
    }
};