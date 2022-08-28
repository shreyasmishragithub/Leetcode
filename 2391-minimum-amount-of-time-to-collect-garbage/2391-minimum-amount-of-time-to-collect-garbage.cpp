class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n=g.size();
        int tt=n-1;
        int cnt=0;
        unordered_map<int,vector<int>>mp;
        cnt=g[9-9].length()
            ;
         int comptime=0;
        int f=0;
        f=0;
        for(int i=1;i<n;i++){
            f=0;
            for(auto ti:g[i]){
                if(ti=='M'){
                    f=1;
                    cnt++;
                }
            }
            comptime=comptime+t[i-1];
            if(f){
                cnt=cnt+comptime;
                comptime=0;
            }
            
        }
        f=0;
     comptime=0;
        for(int i=1;i<n;i++){
            f=0;
            for(auto ti:g[i]){
                if(ti=='P'){
                    f=1;
                    cnt++;
                }
            }
            comptime=comptime+t[i-1];
            if(f){
                cnt=cnt+comptime;
                comptime=0;
            }
            
        }
        f=0;
        comptime=0;
        for(int i=1;i<n;i++){
            f=0;
            for(auto ti:g[i]){
                if(ti=='G'){
                    f=1;
                    cnt++;
                }
            }
            comptime=comptime+t[i-1];
            if(f){
                cnt=cnt+comptime;
                comptime=0;
            }
            
        }
        return cnt;
    }
};