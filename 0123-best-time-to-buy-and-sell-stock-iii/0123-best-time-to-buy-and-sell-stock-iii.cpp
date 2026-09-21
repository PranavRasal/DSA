class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0 ;
        int buy = prices[0] ;
        int n = prices.size() ;
        if ( n < 2){
            return 0 ;
        }
        vector<int>stor(n , 0) ;
        int sell = prices[n-1] ;
        for(int i = n - 2 ; i >= 0 ; i--){
            int profit = sell - prices[i] ;
            stor[i] = max(stor[i+1],profit) ;
            sell = max(sell , prices[i]) ;
        }
        for(int i = 1 ; i < n  ; i++){
            int amount = prices[i] - buy ;
            int amount2 = 0 ;
            if(i+1 < n){
            amount2 = stor[i+1] ;
             }
            profit = max(amount + amount2 , profit) ;
            buy = min(buy , prices[i]) ;
        }
        return profit ;
    }
};