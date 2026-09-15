class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        int minNum = nums[n-1] ;
        int maxNum = 0 ;
        vector<int> small(n) ;
        small[n-1] = minNum ;
        // min number i to n -1 
        for(int i = n - 2 ; i >= 0 ; i--){
            if(minNum >= nums[i]){
                minNum = nums[i] ;
            }
            small[i] = minNum ;
        }
        for(int i = 0 ; i < n ; i++){
            if(maxNum < nums[i]){
                maxNum = nums[i] ;
            }
            if((maxNum - small[i]) <= k){
                return i ;
            }
        }
        return -1 ;
    }
};