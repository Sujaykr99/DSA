class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int left = 0 ;
        int right =0 ; 
        int zerocount = 0 ;
        int maxlen = 0 ;

        while(right<nums.size()){
            
            if(nums[right]==0){
                zerocount++ ;
            }

            if(zerocount>1){

                if(nums[left]==0){
                    zerocount-- ;
                }

                left++ ;
            }
            right++ ;

        maxlen = max(maxlen , right-left) ;
        }
       
       return maxlen-1 ;
        
    }
};