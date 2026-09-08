class Solution {
public:
    bool solve(vector<int>& nums , int size , int k){
        int count = 1 ;
        int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(sum + nums[i] > size){
                count++ ;
                sum = nums[i] ;
            }else{
                sum += nums[i] ;
            }
        }
        return count <= k ;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        int total = 0 ;
        int large = 0 ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            total += nums[i] ;
            if(large < nums[i]){
                large = nums[i] ;
            }
        }
        
        if(k == 1) return total ; 
        int st = large ;
        int end = total ;
        while(st <= end){
            int mid = st + (end - st ) / 2 ;
            if(solve(nums , mid , k)){
                ans = mid ;
                end = mid - 1 ;
            }else{
                st = mid + 1 ;
            }
        }
        return ans ;
    }
};