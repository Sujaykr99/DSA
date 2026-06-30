class Solution {
    private :
    void solve(vector<int>nums , int idx ,  vector<vector<int>>&ans){
        //base case 
        if(idx == nums.size()){
            ans.push_back(nums) ;
        }
        // int currentidx = 0 ;
        for(int i = idx ; i < nums.size() ; i++){
            swap(nums[i] , nums[idx]) ; 
            solve(nums , idx+1 ,ans ) ;
            swap(nums[idx], nums[i]) ;
            // ans.push_back(nums[i]) ;
            // idx++ ; 
           

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans ;
        // vector<int>output ; 
        int idx = 0 ;
        solve(nums , idx , ans ) ;
        return ans ;
    }
};