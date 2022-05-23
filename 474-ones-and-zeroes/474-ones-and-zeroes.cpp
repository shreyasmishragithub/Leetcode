class Solution {
public:
    int ans=0;
    int dp[602][101][101];
    int go(int m,int n,int ze,int one,vector<string>&s,int idx){
        if(idx>=s.size()){
            return 0;
        }
        int x=count(s[idx].begin(),s[idx].end(),'0');
        int y=s[idx].size()-x;
        int xx,yy;
        xx=yy=0;
        if(dp[idx][ze][one]!=-1){
            return dp[idx][ze][one];
        }
        if(m>=ze+x&&one+y<=n)
        xx=1+go(m,n,ze+x,one+y,s,idx+1);
        if(m>=ze&&one<=n){
        yy=go(m,n,ze,one,s,idx+1);
        }
        return dp[idx][ze][one]=max(xx,yy);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        memset(dp,-1,sizeof(dp));
        int x= max(go(m,n,0,0,s,0),0);
        return x;
        
    }
};