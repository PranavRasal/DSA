/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node , Node* cloneNode , unordered_map<Node* , Node*>& mp ){
        for(Node* neig : node->neighbors){
            if(mp.find(neig) == mp.end()){
                Node* clone =new Node( neig->val) ;
                cloneNode->neighbors.push_back(clone) ;
                mp[neig] = clone ;
                dfs(neig , clone , mp) ;
            }else{
                Node* clone = mp[neig] ;
                cloneNode->neighbors.push_back(clone) ;
                
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node ;
        }
        Node* cloneNode = new Node(node->val) ;
        unordered_map<Node* , Node*> mp ;
        mp[node] = cloneNode ;
        dfs(node , cloneNode , mp) ;
        return cloneNode ;
    }
};