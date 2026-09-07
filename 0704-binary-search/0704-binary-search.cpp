class Solution {
public:
    int search(vector<int>& nums, int target) {

        int beg = 0 ;
        int end = nums.size()-1 ;
        int mid = beg + (end - beg)/2 ;

        while(beg<=end){

            if(nums[mid]==target) 
                return mid ;

            else if(nums[mid] > target) {
                end = mid -1 ;
            }
            else{
                beg = mid+1 ;
            }
            mid = beg + (end-beg)/2 ;
        }
     
      return -1 ;
        
    }
};