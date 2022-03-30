class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        map<int,int> row_count,col_count;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    row_count[i]++,col_count[j]++;
            }
        }
        int ans=0;
         for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] && (row_count[i]>1 || col_count[j]>1 ))
                {
                    ans++;
                    
                }
            }
        }
         return ans;
        
    }
};