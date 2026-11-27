class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n , INT_MAX) ;
        unordered_map<int, vector<pair<int , int>>>  mp ;
        for(auto neigh : flights){
            int from = neigh[0] ;
            int to = neigh[1] ;
            int price = neigh[2] ;
            mp[from].push_back({to , price}) ;
        }
        queue<pair<int , pair<int , int>>> qu ; // node , {cost , stops}
        qu.push({src ,{0 , - 1}}) ;
        dist[src] = 0 ;
        while(qu.size() > 0){
            auto val = qu.front() ;
            int node = val.first ;
            int cost = val.second.first ;
            int stops = val.second.second ;
            qu.pop() ;

            for(auto neigh : mp[node]){
                int v = neigh.first ;
                int wt = neigh.second ;
                if(dist[v] > cost + wt && stops + 1 <= k){
                    dist[v] = cost + wt ;
                    qu.push({v , {dist[v] , stops + 1}}) ;
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst] ;
    }
};