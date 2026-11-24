class Solution {
public:
vector<vector<int>> dp ;
    bool isPalin( string& s , int i , int j){
        while(i <= j ){
            if(s[i] != s[j]){
                return false ;
                
            }
            i++ ; 
            j-- ;
        }
        return true ;
    }
    int solve(string& s , int i , int j){
        if(i >= j || isPalin(s , i , j)){
            return 0 ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = INT_MAX ;
        for(int k = i; k < j ; k++){
            if(isPalin(s, i , k)){
            int cut = 1 + solve(s , k + 1 , j) ;
            ans = min(cut , ans) ;
            }
        }
        return dp[i][j] = ans ;
    }
    int minCut(string s) {
        dp.assign(s.size() , vector<int>(s.size() , -1)) ;
        return solve(s , 0 , s.size() - 1) ;
    }
};