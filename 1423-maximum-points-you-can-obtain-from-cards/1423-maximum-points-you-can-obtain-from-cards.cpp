class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() -1 ;
        int left = 0 ;
        int right = n ;
        int sum = 0 ;
        int maxsum = 0 ;
        for(int i = left ; i < k ; i++){
            sum = sum + cardPoints[i] ;
             maxsum = sum ; 
        }
        for(int i = 0; i < k; i++){
           
            sum = sum - cardPoints[left] ;
           
            sum = sum + cardPoints[right] ;
            left++ ;
             right -- ;
            
            maxsum = max(maxsum , sum) ;
        }
       
        
        
        return maxsum ;
    }
};