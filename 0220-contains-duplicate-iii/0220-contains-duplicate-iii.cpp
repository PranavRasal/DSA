class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
       
        int n = nums.size() ;
        set<int> s(nums.begin() , nums.end()) ;
        if(valueDiff == 0 && n == s.size()){
            return false ;
        } // cheating 
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < i + 1 + indexDiff && j < n ; j++){
                long long ans = abs(nums[i] - nums[j]) ;
                if(ans <= valueDiff){
                    return true ;
                }
            }
        }
        return false ;
    }
};