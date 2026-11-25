class Solution {
public:
    vector<vector<int>> vis ; 
    int longPath(vector<vector<int>>& matrix , int i , int j , int num){
        if(i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || matrix[i][j] <= num ){
            return 0 ;
        }
        if(vis[i][j] != -1){
            return vis[i][j] ;
        }
        
        vis[i][j] = true ;
        int up = 1 + longPath(matrix , i - 1 , j , matrix[i][j]) ;
        int down = 1 + longPath(matrix , i + 1 , j , matrix[i][j]) ;
        int right = 1 + longPath(matrix , i , j+1 , matrix[i][j]) ;
        int left = 1 + longPath(matrix , i , j-1 , matrix[i][j]) ;
        vis[i][j] = false ;
        return vis[i][j] = max({up , down , right , left}) ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vis.assign(n , vector<int>(m , -1)) ;
        int ans = 1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int total = longPath(matrix , i , j , INT_MIN) ;
                ans = max(total , ans) ;
            }
        }
        return ans ;
    }
};