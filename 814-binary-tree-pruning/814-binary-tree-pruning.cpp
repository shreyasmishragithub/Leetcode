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
    void postorder(TreeNode*& root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        if( root->left==NULL && root->right==NULL && root->val==0){
            root=NULL;
            return;
        }

    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }   
        postorder(root);
        return root;
    }
};