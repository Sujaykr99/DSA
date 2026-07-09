class Solution {
    private :
    void solve(vector<int>& candidates,int idx ,vector<vector<int>>&ans ,   vector<int>output ,  int target){
         
         int Remsum = target ; 
        //base case 
        if(Remsum==0){
            ans.push_back(output) ;
            return ;
        }
        if(Remsum<0){
            return ;
        }
        if(idx >= candidates.size()){
             return ;
        }
        int remainingtarget = target ; 
        //include 
        
        solve(candidates , idx+1 , ans ,output , Remsum) ;
        // exclude 

         Remsum = Remsum - candidates[idx] ; 
         output.push_back(candidates[idx]) ;
        solve(candidates , idx , ans ,output , Remsum) ;

        
       

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()) ;
        vector<vector<int>>ans ;
        vector<int>output ; 
        int idx = 0 ; 

        solve( candidates , idx ,ans , output , target );
      
      return ans ;  
    }
};