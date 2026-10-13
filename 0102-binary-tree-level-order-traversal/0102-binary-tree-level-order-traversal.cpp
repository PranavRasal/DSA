/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<vector<int>> ans ;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {} ;
        }
       queue<TreeNode*> qu ;
       qu.push(root) ;
       qu.push(NULL) ;

       vector<vector<int>> ans ;
       while(qu.size() > 1){
            vector<int> temp ;
            while(!qu.empty() && qu.front() != NULL){
                TreeNode* num = qu.front() ;
                qu.pop() ;
                temp.push_back(num->val) ;
                if(num->left != NULL){
                    qu.push(num->left) ;
                }
                if(num->right != NULL){
                    qu.push(num->right) ;
                }
            } 
            if(!qu.empty()){
                qu.pop() ;
            }
            
            ans.push_back(temp) ;

            if(!qu.empty()){
               qu.push(NULL) ; 
            }
       }
        return ans ;
    }
};