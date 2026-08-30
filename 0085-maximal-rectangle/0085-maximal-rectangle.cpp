class Solution {
public:
    int solve(int j , vector<int> high ){
        if(high[j] == 0){
            return 0 ;
        }
        int count = 1 ;
        int i = j - 1 ;
        //left side 
        while( i >= 0){
            if(high[i] == 0 || high[j] > high[i]){
                break ;
            }
            count++ , i-- ;
        }
        i = j + 1 ;
        int n = high.size() ;
        //right
        while( i < n ){
            if(high[i] == 0 || high[j] > high[i]){
                break ;
            }
            count++ , i++ ;
        }
        return high[j] * count ;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
       int n =  matrix.size() ;
       int m = matrix[0].size() ;
       vector<int> high(m , 0) ;
       int result = 0 ;
       for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j] == '1'){
                high[j] += 1 ;
            }else{
                 high[j] = 0 ;
            }
        }
        for(int j = 0 ; j < m ; j++){
            result = max(result , solve(j , high)) ;
        }

       }
       return result ;
    }
};