/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
    
    void serial(TreeNode* root , queue<string>& qu){
        if(root == NULL){
            qu.push("NULL") ;
            return ;
        }
        qu.push(to_string(root->val)) ;
        serial(root->left , qu) ;
        serial(root->right , qu) ;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<string> dummy  ;
        serial(root, dummy) ;
        

        while(!dummy.empty()) {
            ans += dummy.front() + ",";
            dummy.pop();
        }

        return ans;
    }

    TreeNode* deserial(queue<string>& sto){
        if(sto.empty()){
            return NULL ;
        }
        string val = sto.front() ;
        sto.pop() ;
        if(val == "NULL"){
            return NULL ;
        }
        TreeNode* root = new TreeNode(stoi(val)) ;
        root->left = deserial(sto) ;
        root->right = deserial(sto) ;
        return root ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> sto ;
        string temp = "" ;

        for(int i = 0 ; i < data.size() ; i++){
            if(data[i] == ','){
                sto.push(temp) ;
                temp = "" ;
            }else{
                temp += data[i] ;
            }
        }
        return deserial(sto) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));