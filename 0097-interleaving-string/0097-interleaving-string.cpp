class Solution {
public:
    vector<vector<int>> dp ;
    bool helper(string s1, string s2, string s3 , int i , int j ){
        if(i == s1.size() && j == s2.size()){
            return true ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        bool take1 = false ;
        bool take2 = false ; 
        int k = i + j ;
        if(i < s1.size() && s3[k] == s1[i]){
            take1  = helper( s1 , s2 , s3 , i+1 , j ) ;
        }
        if(j < s2.size() && s3[k] == s2[j]){
            take2  = helper( s1 , s2 , s3 , i , j+1 ) ;
        }
        return  dp[i][j] = take1 || take2 ;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() ;
        int m = s2.size() ; 
        int o = s3.size() ;

        if(n + m != o){
            return false ;
        }
        dp.assign(n + 1 , vector<int>(m+1 , -1)) ;
        return helper( s1 , s2 , s3 , 0 , 0);
    }
};