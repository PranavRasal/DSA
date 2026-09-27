/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* findNode(Node* root){
        Node* nextPoint = root->next ;
        while ( nextPoint != NULL){
            if(nextPoint->left != NULL){
                return nextPoint->left ;
            }
            if(nextPoint->right != NULL){
                return nextPoint->right ;
            }
            nextPoint = nextPoint->next ;
        }
        return NULL ;
    }
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL ;
        }
        if(root->left != NULL){
            if(root->right != NULL){
                root->left->next = root->right ;
            }else{
                 root->left->next = findNode(root) ;
            }
        }
        if(root->right != NULL){
            root->right->next = findNode(root) ;
        }connect(root->right);
        connect(root->left);
        
        return root ;
    }
};