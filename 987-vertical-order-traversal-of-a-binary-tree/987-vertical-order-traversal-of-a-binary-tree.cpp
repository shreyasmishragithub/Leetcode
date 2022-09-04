class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {{}};
        
        //queue for level order traversal
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        
        // answer map ->> {vertical level, {vertical level element}}
        map<int, vector<int>>mp;
        while(!q.empty()){
            int sz = q.size();            
            //temporary map for storing ans for this height
            map<int, vector<int>>temp;
            while(sz--){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                temp[level].push_back(node->val);
                if(node->left != NULL){
                    q.push({node->left, level-1});
                }
                if(node->right != NULL){
                    q.push({node->right, level+1});
                }
            }
            
            //Pushing into ans map
            for(auto it : temp){
                int level = it.first;
                vector<int>curr = it.second;
                sort(curr.begin(), curr.end());
                for(auto ele : curr){
                    mp[level].push_back(ele);
                }
            }
        }        
        
        //Creating ans vector<vector<int>> from map
        vector<vector<int>>res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        
        return res;        
    }
};