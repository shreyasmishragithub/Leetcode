class Solution {
public:
    bool check(vector<int>adj[],int s,vector<int>&color,int i){
        for(auto &it:adj[s]){
            if(i==color[it]){
                return false;
            }
        }
        return true;
    }
    int f=0;
    bool dfs(int par,int s,vector<int>adj[],vector<int>&color,vector<int>&visi,int n,int cnt,vector<int>&coloo){
        visi[s]=1;
        for(int i=1;i<=4;i++){
            if(check(adj,s,color,i)==1){
                color[s]=i;
                for(auto &it:adj[s]){
                    if(visi[it]==-1){
                    if(dfs(s,it,adj,color,visi,n,cnt+1,coloo)==true){
                        return true;
                    }
                    color[s]=0;
                        }
                }
            }
        }
        return true;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        if(!paths.size()){
            vector<int>nn;
            for(int i=0;i<n;i++){
                nn.push_back(1);
            }
            return nn;
        }
        vector<int>adj[n+1];
        for(auto it:paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>coloo(n+1);
        vector<int>color(n+1);
        color[0]=5;
        int cnt=1;
        vector<int>visi(n+1,-1);
        visi[0]=1;
        for(int i=1;i<=n;i++){
            if(visi[i]==-1){
            dfs(0,i,adj,color,visi,n,cnt,coloo);
            }
            
        }
        vector<int>colo(n);
        for(int i=0;i<n;i++){
            colo[i]=color[i+1];
        }
        return colo;
        
    }
};