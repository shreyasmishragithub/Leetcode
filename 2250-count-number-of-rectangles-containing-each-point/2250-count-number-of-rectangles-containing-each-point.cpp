class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n=rectangles.size();
        int m=points.size();
        vector<vector<int>>bucket(101);
        for(auto &it:rectangles){
            int x=/*r*/it[0];
            int y=/*r*/it[1];
            bucket[y].push_back(x);
        }
        for(auto &it:bucket){
            sort(it.begin(),it.end());
        }
        vector<int>ans(m);
        int idx/*x*/=0;
        for(int i=0;i<m;i++){
            int x=points[i][0];
            int y=points[i][1];
            int sum=0;
            for(int k=y;k<=100;k++){
                sum+=bucket[k].end()-lower_bound(bucket[k].begin(),bucket[k].end(),x);
            }
            ans[idx++]=sum;
        }
        return ans;
    }
};