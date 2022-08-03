class Solution {
stack<int> s;

bool dfs(int i, vector<bool> &vis, vector<bool> &dfsvis,  vector<vector<int>> &adj ){
    
    vis[i] = true;
    dfsvis[i] = true;
    
    for(auto it : adj[i]){
        
        if(!vis[it]){
            
            if(dfs(it,vis,dfsvis,adj)) return true;
            
        }else if(dfsvis[it]) return true;
    }
    
    dfsvis[i] = false;
    s.push(i);
    return false;
}
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);
    
    for(auto i : prerequisites){
        
        adj[i[1]].push_back(i[0]);
    }
    
    
    vector<bool> vis(numCourses, false);
    vector<bool> dfsvis(numCourses, false);
    
    
    
    for(int i = 0; i<numCourses;i++ ){
        
        if(!vis[i]){
            if(dfs(i,vis,dfsvis,adj)) {
                return {};
            }       
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
};