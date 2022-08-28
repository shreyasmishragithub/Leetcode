class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            vector<int>v;
            int cnt=0;
            int ii=i;
            while(ii<n and cnt<m){
                v.push_back(mat[ii][cnt]);
                ii++;
                cnt++;
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
             cnt=0;
             ii=i;
            while(ii<n and cnt<m){
                mat[ii][cnt]=v.back();
                v.pop_back();
                ii++;
                cnt++;
            }
            
        }
        for(int j=0;j<m;j++){
            
            vector<int>v;
            int cnt=0;
            int ii=j;
            while(ii<m and cnt<n){
                v.push_back(mat[cnt][ii]);
                ii++;
                cnt++;
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
             cnt=0;
             ii=j;
            while(ii<m and cnt<n){
                mat[cnt][ii]=v.back();
                v.pop_back();
                ii++;
                cnt++;
            }
        }
        return mat;
    }
};