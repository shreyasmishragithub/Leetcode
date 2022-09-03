class Solution {
public:
    bool isvalid(int i, int j, int m , int n)
   {
       if(i<0 || j<0 || i>=m || j>=n) return false;
       return true;
   }
    int cx[4]={-1,1,0,0};
    int cy[4]={0,0,-1,1};
    void dfs( vector<vector<int>>&h,vector<vector<bool>>&vis , int i, int j,int m ,int n)
    {
        
        
               vis[i][j]=1;
               for(int k=0;k<4;k++)
                {
                    int X=i+cx[k];
                    int Y=j+cy[k];
                    if(isvalid(X,Y,m,n)&& vis[X][Y]==0&&  h[X][Y]>=h[i][j])
                    {
                       
                        dfs(h,vis,X,Y,m,n);
                    }
               }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) 
    {
         
        vector<vector<int>>r;
        int m = h.size();
        if (m == 0)
            return r;
        int n = h[0].size();
        if (n == 0)
            return r;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            dfs(h, pacific, i, 0,m,n);
            dfs(h, atlantic, i, n-1,m,n);

        }
        for (int j = 0; j < n; j++) {
            dfs(h, pacific, 0, j,m,n);
            dfs(h, atlantic, m-1, j,m,n);
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                {
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(j);
                    r.push_back(v);
                }
            }
        }
        return r;
    }
};