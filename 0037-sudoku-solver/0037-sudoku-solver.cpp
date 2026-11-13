class Solution {
bool isSafe(int row , int col , vector<vector<char>>&board , char val){
      int n = board[0].size() ;
    for(int i = 0 ; i< n ; i++){
        //row check 
        if(board[row][i]==val){
            return false ;
        }
        if(board[i][col]==val){
            return false ;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+ i%3]==val){
            return false ;
        }
       
    }
     return true ;
};
bool solve(vector<vector<char>>&board){
    int n = board[0].size() ;

    for(int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++){

            //cell empty 
            if(board[i][j]=='.'){
                for(int val = '1' ; val <=  '9' ; val++){
                    if(isSafe(i , j , board , val)) {
                        board[i][j] = val ;
                    // recursive call 
                    bool Nextans = solve(board) ;
                    if(Nextans) return true ;
                    else {
                        //backtrack 
                        board[i][j] = '.' ;
                    }

                    }
                }
                return false ;
            }
        }
    }
    return true ;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board) ;
    }
};