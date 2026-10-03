class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        
            if(nums[0] == 1) {return 0 ;} 
        
        for(int i = 0 ; i < nums.size() ; i++){
            if( i + 1  < nums.size() && nums[i+1] > nums[i] + 1 ){
                return i+1 ;
            }
        }
        return nums.size()  ;
    }
};