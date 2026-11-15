class Solution {
public:
    void solve(int n, int k,int start, vector<int>&temp , vector<vector<int>>& ans) {

        // base case
        if (temp.size() == k) {

            ans.push_back(temp);
            return;
        }
        // recursive call
        for(int idx = start ; idx <= n ; idx++ ){
            //temp mein i add karo.
            temp.push_back(idx) ;

            //Recursive call karo, next start i+1 ke saath.
            solve(n , k , idx+1 , temp ,ans) ;

            //Backtracking karo.
            temp.pop_back() ;
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;

        vector<int> temp;

        solve(n, k, 1 , temp , ans);

        return ans;
    }
};