class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int n=mat.size();
        bool check90=1,check180=1,check270=1,check360=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]!=tar[i][j]) check360=0;
                if(mat[i][j]!=tar[n-j-1][i]) check90=0;
                if(mat[i][j]!=tar[n-i-1][n-j-1]) check180=0;
                if(mat[i][j]!=tar[j][n-i-1]) check270=0;
            }
        if(check90 | check180 | check270 | check360) return 1;
        return 0;
    }
};