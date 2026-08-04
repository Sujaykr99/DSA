class Solution {
    private:
    bool solve(int n ){

        //base case 
        if(n==1) return true ; 

        if(n<=0||n%3!=0) return false ;
        
        return solve(n/3) ;

    }
public:
    bool isPowerOfThree(int n) {
        //BY loop 
        // for(int i = 0 ; i < 20 ; i++){
        //     long long ans = pow(3,i) ;
        //     if(ans == n) return true ;
        // }
        // return false ;

        //by recusion
        bool ans = solve(n) ;
       return ans ;
    }
};