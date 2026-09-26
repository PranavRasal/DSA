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
    void helper(TreeNode* root, int targetSum , vector<int>stor , int sum){
        if(root == NULL){
            return ;
        }
        sum += root->val ;
        stor.push_back(root->val) ;
        if(sum == targetSum && root->left == NULL && root->right == NULL ){
            ans.push_back(stor);
        }
        helper(root->left ,  targetSum , stor , sum) ;
        helper(root->right ,  targetSum , stor , sum) ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> stor ;
        if(root == NULL ){
            return ans ;
        }
        helper(root,  targetSum , stor , 0) ;
        return ans ;
    }
};