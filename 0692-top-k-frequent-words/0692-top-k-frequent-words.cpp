class Solution {
public:
    static bool comp(pair<int , string> a , pair<int , string> b ){
        if(a.first == b.first) return a.second > b.second;

        return a.first < b.first ;

    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int > stor;
        
        for(int i = 0 ; i < words.size() ; i++){
            stor[words[i]]++ ;
        }
        priority_queue<pair<int , string> , vector<pair<int , string>> , decltype(&comp) > fre(comp) ;
        for(auto element : stor){
           string s =  element.first ;
           int num = element.second;
           fre.push({num , s}) ;
        }
        vector<string> ans ;
        for(int i = 0 ; i < k ; i++){
            auto n = fre.top() ;
            fre.pop() ;
            ans.push_back(n.second) ;
        }
        return ans ;
    }
};