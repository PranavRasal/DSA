class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        if(n == 1){
            return 1 ;
        }
        int result = 0 ;
        for(int i = 0 ; i < n ; i++){ 
            for(int j = i+1 ; j < n ; j++){
                int count = 2 ;
                int dy = points[i][1] - points[j][1] ;
                int dx = points[i][0] - points[j][0] ;
                
                for(int k = 0 ; k < n ; k++){
                    if(k == i || k == j){
                        continue ;
                    }
                    int dy_ = points[k][1] - points[j][1] ;
                    int dx_ = points[k][0] - points[j][0] ;
                    int slop_ = dy*dx_ ;
                    int slop = dy_*dx ;
                    if(slop == slop_){
                        count++ ;
                    }
                }
                result = max(result , count) ;
            }
        }
        return result ;
    }
};