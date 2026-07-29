class Solution {

private:
    int atMost(vector<int>& nums, int k){
        int left = 0 ;
        int right = 0 ; 
        int oddcount = 0 ;
        int count = 0 ;

        while(right<nums.size()){
               
             if (nums[right] % 2 != 0)
                oddcount++;
            
              
            while(oddcount>k){
               if(nums[left]%2){
                oddcount -- ;
               }
               left++ ;
            }

            count += right-left+1 ;
            right++ ;

        }
        return count ; 

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     
     return atMost(nums, k) - atMost(nums, k - 1);   
    }
};