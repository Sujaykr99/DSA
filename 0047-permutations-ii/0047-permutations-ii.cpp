class Solution {
private:
    void solve(vector<int> nums, vector<int>& output, int idx,
               vector<vector<int>>& ans) {

        // base case
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for (int i = idx; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end())
                continue;

            seen.insert(nums[i]);

            swap(nums[i], nums[idx]);
            solve(nums, output , idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int idx = 0;
        solve(nums, output, idx, ans);
        return ans;
    }
};