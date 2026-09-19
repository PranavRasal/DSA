class Solution {
public:
vector<vector<int>> dp ;
    bool helper(string s, string p , int i , int j){
        if(j == p.size()){
            if(i == s.size()){
                return true ;
            }
            return false ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        bool pass = false ;
        if(i < s.size() && (s[i] == p[j] || p[j] == '.') ){
            pass = true  ;
        }
        if( j + 1 < p.size() && p[j+1] =='*' ){
            bool take =( pass && helper(s,p , i + 1 , j )) ;
            bool notTake = helper(s , p , i  , j + 2 ) ;
            return dp[i][j] = take || notTake ;
        }
        return dp[i][j] = pass && helper(s,p, i+1 , j+1) ;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1 , vector<int>(p.size() + 1 , -1)) ;
        return helper(s , p , 0 , 0) ;
    }
};