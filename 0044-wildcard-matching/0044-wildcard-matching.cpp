class Solution {
public:
    vector<vector<int>> dp ;
    bool match( string& s , string& p , int i , int j){
        if(j == p.size() && i == s.size()){
            return   true ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        if(p[j] == '*'){
            bool empty = match(s , p , i , j+1) ;
            bool take = false ;
            if(i < s.size()){
            take = match(s, p , i+1 , j) ;
            }
            return dp[i][j] = take || empty ;
        }
        if(i == s.size()){
            return dp[i][j] = false ;
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = match(s , p , i+1 , j+1) ;
        }
        return dp[i][j] = false ;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1 , vector<int>(p.size() + 1 , -1)) ;
        return match(s , p , 0 , 0) ;
    }
};