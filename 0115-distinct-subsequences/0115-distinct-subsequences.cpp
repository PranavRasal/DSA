class Solution {
public:
    long long dp[1001][1001] ;
    long long solve(string s, string t , int i , int j){
        if(j == t.size()){
            return 1 ;
            }
        if(i == s.size()){
            return 0 ;
            }
            if(dp[i][j] != -1){
                return dp[i][j] ;
            }
        if(s[i] == t[j]){
            return dp[i][j] = solve( s , t , i + 1 , j + 1) + solve( s , t , i + 1 , j) ;
        }else{
            return dp[i][j] = solve( s , t , i + 1 , j) ;
        }
        return 0 ;
    }
    int numDistinct(string s, string t) {
        memset(dp , -1 , sizeof(dp)) ;
        return solve( s , t , 0 , 0 ) ;
    }
};