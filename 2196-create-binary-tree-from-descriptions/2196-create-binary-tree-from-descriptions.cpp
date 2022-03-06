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
    TreeNode* dfs(int x,vector<pair<int,int>>aa[],int p){
        TreeNode* root=new TreeNode(x);
        for(auto it:aa[x]){
            if(it.second==1){
                root->left=dfs(it.first,aa,p);
            }
            if(it.second/*1*/==0){
                root->right=dfs(it.first,aa,p);
            }
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        vector<int>innode(100002,0);
        vector<pair<int,int>>aa[100022];
        for(int i=0;i<d.size();i++){
            
            int a=d[i][0];
            int b=d[i][1];
            int lr=d[i][2];
            aa[a].push_back({b,lr});
            innode[b]++;
        }
        int x=0;
        for(int i=0;i<d.size();i++){
            int val=d[i][0];
            if(innode[val]==0){//This means that val is the root
                x=val;
                break;
            }
        }
        int p=-1;
       return  dfs(x,aa,p);//dfs on root kind of copying exactly same adjacency list to TreeNode binary structure
        
      
    }
};