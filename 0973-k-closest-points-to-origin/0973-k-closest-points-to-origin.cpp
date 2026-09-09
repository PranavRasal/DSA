class Solution {
public:
    priority_queue<pair<int ,int>> pq ;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i = 0 ; i < points.size() ; i++){
            int ans = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]) ;
            pq.push({ans , i}) ;
        }
        while(pq.size() > k){
            pq.pop() ;
        }
        vector<vector<int>> ans(k , vector<int>(2)) ;
        for(int i = k -1 ; i >= 0 ; i--){
            int j = pq.top().second ;
            ans[i][0] = points[j][0] ;
            ans[i][1] = points[j][1] ;
            pq.pop() ;
        }
        return ans ;
    }
};