class Solution {
vector<TreeNode*> solve(int start , int end , map<pair<int, int> , vector<TreeNode*>> &mp)
{
vector<TreeNode*> ans;

    if(start > end)
    {
        ans.push_back(NULL);  
        return ans; 
    }
     if( start == end)
     {
        TreeNode *temp = new TreeNode(start); 
         ans.push_back(temp); 
         return ans;
     }   
    
    if(mp.find({start, end})!= mp.end())
        return mp[{start,end}]; 
     for(int i = start ; i<= end; i++)
     { 
        vector<TreeNode*> left, right;  
        
         left = solve(start, i - 1, mp ); 
         right = solve(i + 1, end, mp); 
         for(auto l : left)
         {
             for(auto r : right)
             {
                  TreeNode *root = new TreeNode(i); 
                  root->left = l; 
                  root->right = r ; 
                 ans.push_back(root); 
             }
         }
     }
        return mp[{start, end}] = ans; 
    }
public:
vector<TreeNode*> generateTrees(int n)
{
map<pair<int, int> , vector<TreeNode*>> mp;
return solve(1, n,mp);
}
};