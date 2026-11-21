class Solution {
public:
vector<vector<int>> dp ;
    int calCoin(vector<int>& coins, int amount , int i , int count){
        if(amount == 0){
            return 0 ;
        }
        if(i == coins.size() || amount < 0){
            return INT_MAX ;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount] ;
        }
        int take =  calCoin(coins , amount - coins[i] , i , count ) ;
        if(take != INT_MAX) {
            take = 1 + take;
        }
        int notTake = calCoin(coins , amount  , i + 1 , count ) ;
        return dp[i][amount] = min(take , notTake) ;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin() , coins.end()) ;
        int n = coins.size() ;
        dp.assign(n , vector<int>(amount+1 , -1));
        int ans = calCoin(coins ,amount , 0 , 0) ;
        if(ans == INT_MAX){
            return -1 ;
        }
        return ans ;
    }
};