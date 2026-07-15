class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0 ;
        int right = height.size()-1 ; 

        int ans = INT_MIN ;

        while(left<=right){
               int width = right - left ;
               int heigh = min(height[left],height[right]) ;

               int area = (width)*(heigh) ;

               ans = max(ans , area ) ;

               if(height[left]<height[right]){
                   left++ ;
               }
               else 
               right -- ;



        }

        return ans ;
        
    }
};