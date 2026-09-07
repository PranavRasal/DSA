class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size() ; // row 
        int m = matrix[0].size() ; // column
        vector<vector<int>> ans ( m , vector<int>(n)) ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               ans[i][j] = matrix[j][i] ;
            }
        }
        return ans ;
    }
};