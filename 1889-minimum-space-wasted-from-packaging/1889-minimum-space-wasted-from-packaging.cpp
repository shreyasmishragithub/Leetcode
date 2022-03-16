#define all(x) x.begin(),x.end()
class Solution {
public:
    int minWastedSpace(vector<int>& a, vector<vector<int>>& b) {
        int n=a.size();
        int m=b.size();
        sort(a.begin(),a.end());
        long long t=accumulate(all(a),0L);
        long long mintotwaste=LONG_LONG_MAX;
        for(auto it:b){
            sort(it.begin(),it.end());
            vector<int>x=it;
            if(x[x.size()-1]<a[n-1]){
                continue;
            }
            long long mintotlocal=0;
            int i=0;
            for(auto boxes:x){
                int j=upper_bound(a.begin()+i,a.end(),boxes)-a.begin()-1;
                long long selected=j-i+1;
                mintotlocal=mintotlocal+(long long)(boxes*selected);
                i=j+1;
            }
            mintotwaste=min(mintotwaste,mintotlocal);
        }
        if(mintotwaste==LONG_LONG_MAX){
            return -1;
        }
        else{
 return (mintotwaste-t)%1000000007;           
}
    }
};