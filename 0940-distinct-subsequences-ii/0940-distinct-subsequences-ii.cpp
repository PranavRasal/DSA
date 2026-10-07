class Solution {
public:
long long MOD =1e9 + 7 ;
vector<int> dp ;
int solve( vector<int>preView , int n ){
    
    if(n < 0){
        return 1 ;
    }
    if(dp[n] != -1){
        return dp[n] ;
    }
    long long total = (2LL * solve(preView , n -1 )) % MOD ;
    if(preView[n] != -1){
        total = (total - solve(preView , preView[n]-1)+ MOD)%MOD ;
    }
    return dp[n] = total ;
}
    int distinctSubseqII(string s) {
        dp.assign(2001 , -1) ;
        vector<int> lastView(26 , -1) ;
        vector<int>preView(s.size()) ;
        for(int i = 0 ; i < s.size() ; i++){
            int idx = s[i] - 'a' ;
            int last = lastView[idx] ;
             preView[i] = last ;
            lastView[idx] = i ;
        }
        return (solve(preView , s.size()-1) -1 + MOD ) % MOD ;
    }
};