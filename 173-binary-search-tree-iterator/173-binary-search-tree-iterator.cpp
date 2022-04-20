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
class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        TreeNode* rooty=root;
        while(rooty){
            s.push(rooty);
            rooty=rooty->left;
        }
    }
    
    int next() {
        
        TreeNode* topgun=s.top();
        s.pop();
        if(topgun->right!=nullptr){
            TreeNode* rooty=topgun->right;
        while(rooty){
            s.push(rooty);
            rooty=rooty->left;
        }
        }
        return topgun->val;
        }
    
    bool hasNext() {
        if(s.empty()!=true){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */