class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int>(n , - 1)) ;
        int num = 1 ;
        int limit = n * n ;

        int topLimit = 0 ;
        int rightSide = n-1  ;
        int leftSide = 0 ;
        int downLimit = n - 1 ;

        while(num <= limit){
            // top
            for(int i = topLimit ; i <= rightSide ; i++){
                ans[topLimit][i] = num ;
                num++ ;
            }
            topLimit++ ;

            //right down 
            for(int i = topLimit ; i <= rightSide ; i++){
                 ans[i][rightSide] = num ;
                num++ ;
            }
            rightSide-- ;

            //down right to left 
            for(int i = rightSide ; i >= leftSide ; i--){
                ans[downLimit][i] = num ;
                num++ ;
            }
            downLimit-- ;

            // up 
            for(int i = downLimit ; i >= topLimit ; i--){
                ans[i][leftSide ] = num ;
                num++ ;
            }
            leftSide++ ;
        }

        return ans ;
    }
};