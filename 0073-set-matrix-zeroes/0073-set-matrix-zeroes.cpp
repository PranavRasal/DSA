class Solution {
public:
    

    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> visi = matrix ;
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        for(int i = 0 ; i <  matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
             if(visi[i][j] == 0){

               for(int row = 0 ; row < n ; row++){
                   matrix[row][j] = 0 ;
                }
                for(int col = 0 ; col < m ; col++){
                     matrix[i][col] = 0 ;
                 } 
             }
            }
        }
    }
};