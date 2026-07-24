class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
            int left = 0 ; 
        int right = 0 ; 
        int maxlen = 0 ; 
        int zeroCount = 0 ;

        while(right<nums.size()){

              if (nums[right] == 0)
                zeroCount++;

             
           
            if (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

        
          
        maxlen = max(maxlen , right-left+1) ;
         right++ ;

    }

    return maxlen ;
    }
};