class Solution {
    private:
 void solve(vector<int>& candidates, int target ,vector<vector<int>>&ans ,  vector<int>output , int idx){
    
      if(target==0){
        ans.push_back(output) ;
        return ;
      }
      if(target<0){
        return ;
      }
      if(idx>=candidates.size()){
        return ;
      }
  

      for(int i = idx ; i < candidates.size() ; i++){

         if (i > idx && candidates[i] == candidates[i - 1])
                continue;
        
        output.push_back(candidates[i]) ;
       
        solve(candidates , target-candidates[i] , ans ,output , i+1 );
   
        output.pop_back() ;
      }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin() , candidates.end()) ;
        vector<vector<int>>ans ;
        vector<int>output ; 
        int idx = 0 ; 

        solve( candidates , target , ans ,output , idx);
      
      return ans ;  
    }
};