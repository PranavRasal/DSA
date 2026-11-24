class Solution {
public:
    vector<vector<bool>> vis ;
    bool swinPath(vector<vector<int>>& grid , int i , int j , int t){
        int n =  grid.size() ;
        if(i < 0 || j < 0 || i == n || j == grid.size() || vis[i][j] == true || grid[i][j] > t){
            return false ;
        }
        if(i == n - 1 && j == n - 1){
            return true ;
        }
        vis[i][j] = true ;
        int up = swinPath(grid , i - 1 , j , t) ;
        int down = swinPath(grid , i + 1 , j , t) ;
        int right = swinPath(grid , i  , j + 1 , t) ;
        int left = swinPath(grid , i  , j - 1, t) ;
        
        return up || down || right || left ;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ;
        
        int l = grid[0][0] ;
        int r = n*n - 1 ;
        int ans = 0 ;
        while(l <= r){
            int mid = l + (r-l) / 2 ;
            vis.assign( n  , vector<bool>(n , false)) ;
            if(swinPath(grid , 0 , 0 , mid)){
                r = mid - 1 ;
                ans = mid ;
            }else{
                l = mid + 1 ;
            }
        }
         return ans ;
    }
};