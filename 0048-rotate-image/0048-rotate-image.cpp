class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix1 = matrix ;
        int n = matrix.size() ;
        int m = n - 1;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                matrix1[j][m] = matrix[i][j] ;
            }
            m-- ;
        }
        matrix = matrix1 ;
    }
};