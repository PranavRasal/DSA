class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> qu;
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) {
                continue;
            }

            st.insert(nums[i]);
            qu.push(nums[i]);

            if(qu.size() > 3) {
                st.erase(qu.top());
                qu.pop();
            }
        }

        if(qu.size() < 3) {
            while(qu.size() > 1) {
                qu.pop();
            }
        }

        return qu.top();
    }
};