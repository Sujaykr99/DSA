class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int>ans ;

        for(int i = 0 ; i < nums.size() ; i++){
            
            bool found = false ;
            
              for(int j = 1 ; j < nums.size() ; j++){

                int index = (i + j) % nums.size() ;

                   if(nums[index]>nums[i]){

                    ans.push_back(nums[index]) ;
                    found = true ;
                    break ;
                   }
              }

            if(found== false){
                ans.push_back(-1) ;
            }
        }
    return ans ;
        
    }
};