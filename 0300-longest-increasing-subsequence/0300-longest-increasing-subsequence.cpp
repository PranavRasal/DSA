class Solution {
public:
   vector<vector<int>> dp;
    int solve(vector<int>& nums , int i , int prev){
        if(i == nums.size()){
            return 0 ;
        }
        if(dp[i][prev + 1] != -1){
            return dp[i][prev + 1] ;
        }
        int take = 0 ;
        int notTake =  solve(nums , i+1 , prev) ; ;
        if(prev == -1 ||  nums[i] > nums[prev]){
            take =  1 + solve(nums , i+1 , i) ;
        }
        return dp[i][prev + 1] = max(take , notTake) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        dp.assign(n , vector<int>(n+1 , -1)) ;
        return solve(nums , 0 , -1)  ;
    }
};