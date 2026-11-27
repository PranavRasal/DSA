class Solution {
public:
    vector<vector<bool>> vis ;
    void helper(vector<vector<char>>& board , int i , int j){
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == 'X' || vis[i][j] == true){
            return ;
        }
        board[i][j] = '#' ;
        vis[i][j] = true ;
        helper(board , i+1 , j) ;
        helper(board , i-1 , j) ;
        helper(board , i , j+1) ;
        helper(board , i , j-1) ;
    }
    void solve(vector<vector<char>>& board) {
         if(board.empty() || board[0].empty()){
        return;
    }
        
        int n = board.size() ;
        int m = board[0].size() ;
        vis.assign(n , vector<bool>(m , false)) ;
        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O') {
                helper(board , 0 , i) ;
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(board[n-1][i] == 'O') {
                helper(board , n-1 , i) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O') {
                helper(board , i , 0) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][m-1] == 'O') {
                helper(board , i , m-1) ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X' ;
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O' ;
                }
            }
        }
        
    }
};