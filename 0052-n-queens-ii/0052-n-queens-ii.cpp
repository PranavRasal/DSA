class Solution {
public:
    int total = 0 ;
    void solve(int n , vector<vector<bool>> check , int row , int col ){
        if(row == n ){
            return ;
        }
        // up 
        for(int i = row - 1  ; i >= 0  ; i--){
            if(check[i][col]){
                return ;
            }
        }
        
        // right diago
        int rowCount = row - 1  , colCount = col - 1 ;
        while(rowCount >= 0 && colCount >= 0){
            if(check[rowCount--][colCount--]){
                return  ;
            }
        }

        //left diago
        rowCount = row - 1  , colCount = col + 1 ;
        while(rowCount >= 0 && colCount < n ){
            if(check[rowCount--][colCount++]){
                return  ;
            }
        }
        if(row == n-1 ){
            total++ ;
            return ;
        }

        check[row][col] = true ;

        
        for(int i = 0 ; i < n ; i++){
             solve( n , check , row + 1 , i) ;
        }
         
       
    } 
    
    int totalNQueens(int n) {
        
        vector<vector<bool>>check(n , vector<bool>(n , false)) ;
        for(int i = 0 ; i < n ; i++){
             solve( n , check , 0 , i) ;    
        }
        return total ;
    }
};