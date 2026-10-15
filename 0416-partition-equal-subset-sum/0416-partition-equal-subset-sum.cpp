class Solution {
public:
    vector<vector<int>> dp ;
    bool helper(vector<int>& nums , int sum , int i , int target){
        if(sum == target){
            return true ;
        }
        if(i == nums.size()){
            return false ;
        }
        if(dp[sum][i] != -1){
            return dp[sum][i] ;
        }
        bool take = helper(nums , sum + nums[i] , i + 1 , target) ;
        bool notTake = helper(nums , sum  , i + 1 , target) ;
        return dp[sum][i] = take || notTake ;
    }
    bool canPartition(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int sum = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i] ;
        }
        if(sum% 2 != 0 || (sum / 2) < nums[nums.size() - 1]){
            return false ;
        }
        dp.assign(sum , vector<int>(nums.size() , - 1)) ;
        return helper( nums , 0 , 0 , sum/2) ;
    }
};