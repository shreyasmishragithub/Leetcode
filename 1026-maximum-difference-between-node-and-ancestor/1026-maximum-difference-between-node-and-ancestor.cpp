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
    int ans=INT_MIN;
    void go(TreeNode* root,vector<int>a,int parent){
        if(root==nullptr){
            return;
        }
        for(auto it:a){
            ans=max(ans,int(abs(it-root->val)));
        }
        a.push_back(root->val);
        go(root->left,a,parent);
        go(root->right,a,parent);
        a.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int>a;
        go(root,a,1);
        return ans;
    }
};