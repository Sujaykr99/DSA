class Solution {
    private:
    int atmost(vector<int>& nums, int goal){
        int left = 0 ;
        int right = 0 ; 
        int sum = 0 ;
        int count = 0 ;
        if (goal < 0)
        return 0;

        while(right<nums.size()){
            
            if(nums[right]==1){
                sum++ ;
            }
            while(sum>goal){
                if(nums[left]==1){
                    sum-- ;
                }
                left++ ;
            }
            count += right-left+1 ;
            right++ ;

        }
        return count ;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atmost(nums , goal) - atmost(nums , goal-1) ;
    }
};