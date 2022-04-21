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
    void go(TreeNode* root,vector<int>&a){
        if(root==nullptr){
            return ;
        }
        go(root->left,a);
        a.push_back(root->val);
        go(root->right,a);
    }
    TreeNode* middy(vector<int>a,int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid=start+end;
        mid/=2;
        TreeNode* aa=new TreeNode(a[mid]);
        aa->left=middy(a,start,mid-1);
        aa->right=middy(a,mid+1,end);
        return aa;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>a;
        go(root,a);
        return middy(a,0,a.size()-1);
    }
};