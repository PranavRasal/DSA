class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0 ;
        }
        sort(nums.begin() , nums.end()) ;
        int ans = nums[1] + nums[2] + nums[0] ;;
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int left = i+1 ;
            int right = nums.size() - 1 ;
            while(left < right){
                int sum = nums[i] + nums[right] + nums[left] ;
                if(sum == target){
                    return sum ;
                }
                if(abs(target - sum) < abs(target - ans)){
                    ans = sum ;
                }
                if(sum > target){
                    right-- ;
                } else if(sum < target){
                    left++ ;
                }
            }
        }
        return ans ;
    }
};