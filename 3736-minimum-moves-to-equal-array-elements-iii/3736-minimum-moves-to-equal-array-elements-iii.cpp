class Solution {
public:
    int minMoves(vector<int>& nums) {

        int count = 0;

        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {

            int sum = maxi - nums[i];

            count += sum;
        }
        return count;
    }
};