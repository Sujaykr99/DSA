class Solution {
    private:  
    void solve(vector<int>nums ,vector<int>output , int index ,vector<vector<int>>&ans){
        //base case 
     if(index>=nums.size()) {
            bool found = false;

    for (auto x : ans) {
        if (x == output) {   
            found = true;
            break;
        }
    }

    if (!found)
        ans.push_back(output);
      return;

        }
        //exclude 
        solve(nums , output , index+1 ,ans) ;
        //include 
        int element = nums[index] ;
        output.push_back(element) ;
        solve(nums , output , index+1 , ans) ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
         vector<vector<int>>ans ; 
        vector<int>output ; 
        int  index = 0 ; 
        solve(nums ,output ,index , ans) ;
        return ans ;
    }
};