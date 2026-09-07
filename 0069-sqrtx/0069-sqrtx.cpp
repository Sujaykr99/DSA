class Solution {
public:
    int mySqrt(int x) {
        
        int s = 0 ;
        int e = x ;
        long long mid = s + (e-s)/2 ;

        long long ans = 0 ;

        if(x==1) return x ;

        while(s<=e){

            long long square = mid*mid ;

            if(square == x){
                return mid ;
            }
            if(square<x){
                ans = mid ;
                s = mid+1 ;
            }
            else{
                e = mid-1 ;
            }
            mid = s +(e-s)/2 ;
        }
        return ans ;
    }
};