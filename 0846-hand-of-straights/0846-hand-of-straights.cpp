class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size() ;
        if(n % groupSize != 0 ){
            return false ;
        }
        map<int , int > mp ;
        for(int i = 0 ; i < n ; i++){
            mp[hand[i]]++ ;
        }
        while(!mp.empty()){
            int first = mp.begin()->first ;
            for(int i = 0 ; i < groupSize ; i++){
                int sear = first + i ;
                if(mp.find(sear) == mp.end()){
                    return false ;
                }
                mp[sear]-- ;
                if(mp[sear] == 0){
                    mp.erase(sear) ;
                }
            }
        }
        return true ;
    }
};