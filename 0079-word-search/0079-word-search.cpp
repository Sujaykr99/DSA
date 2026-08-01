class Solution {
private : 
 bool solve(vector<vector<char>>&board , string word ,int idx ,  int i , int j ,int m, int n ){
      
      if(i<0||j<0||i>=m || j>=n || board[i][j]!=word[idx]) return false ;

      if(idx==word.size()-1) return true ; 

      char c = board[i][j] ; 
      board[i][j] = '#' ;

      bool s1 = solve(board , word , idx+1 , i+1 , j , m , n) ;
      bool s2 = solve(board , word , idx+1 , i , j+1 , m , n ) ;
      bool s3 = solve(board , word , idx+1 , i-1 , j , m , n  ) ;
      int s4 = solve(board , word , idx+1 , i , j-1 , m , n) ;

      board[i][j] = c ;

      return s1||s2||s3||s4 ;
 }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int idx = 0 ;
        int m = board.size() ;
        int n = board[0].size() ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]==word[0]){
                    if(solve(board , word , idx ,i , j ,m ,n )) return true ;
                }
            }
        }

        return false ;

        
    }
};