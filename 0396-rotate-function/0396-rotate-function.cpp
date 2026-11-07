class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0 ;
        long long sum = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++){
            total += nums[i] ;
            sum += i * nums[i] ;
        }
        long long ans = sum;
        for(int i = n-1 ; i > 0 ; i--){
            sum = sum + total - n * nums[i] ;
            ans = max(sum , ans ) ;
        }
        return (int)ans ;
    }
};