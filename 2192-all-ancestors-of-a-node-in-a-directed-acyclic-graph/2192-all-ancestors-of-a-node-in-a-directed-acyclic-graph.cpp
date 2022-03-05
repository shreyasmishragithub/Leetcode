class Solution {
public:
void dfs(int source,vector<int>&res,int vis[],vector<int> v[]){
vis[source]=1;
for(auto it:v[source]){
if(vis[it]) continue;
dfs(it,res,vis,v);
res.push_back(it);
}

}
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    int size=edges.size();
    vector<int> v[n+1];
    for(int i=0;i<size;i++){
        v[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> ans;
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        vector<int> res;
        dfs(i,res,vis,v);
        sort(res.begin(),res.end());
        ans.push_back(res);
        memset(vis,0,sizeof(vis));
    }
    return ans;
}
};