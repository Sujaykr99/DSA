class Solution {
public:
    double myPow(double x, int n) {
      
        long long power = n; 
        
        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }
        return solve(x, power);
   
       
    }
    private : 
    double solve(double x, long long power){
        if(power==0) return 1 ;
        if(power==1) return x ;
         double ans = solve(x,power/2) ; 

        if(power%2==0){
             return ans*ans ;
        }
        else {
             return ans*ans*x ;
        }
   
    }
};