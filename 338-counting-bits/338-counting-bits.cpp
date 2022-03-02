class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans;
        ans.push_back(0);
        
        int k=1;
        int kk=2;
        int t=1;
        while(t<=n){
            
            if(t==kk){
                k=kk;
                kk=kk*2;
            }
            ans.push_back(1+ans[t-k]);
            
            t++;
        }
        return ans;
    }
};
