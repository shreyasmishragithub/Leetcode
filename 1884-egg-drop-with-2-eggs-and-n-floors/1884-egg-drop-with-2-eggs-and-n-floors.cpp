class Solution {
public:
    int dp[1004][2+1];
    int go(int f,int e){
        if(e==1){
            return dp[f][e]=f;
        }
        if(f==1||f==0){
            return dp[f][e]=f;
        }
        if(dp[f][e]==-1){
        }else{
            
            return dp[f][e];
        }
        int mx;int df=INT_MAX;
        for(int i=1;i<=f;i++){
            int jj=i-1;
            int x=1+go(jj,e-1);//broken
            int y=1+go(f-i,e);//not broken
            mx=max(x,y);
            df=min(df,mx);
        }
        return dp[f][e]=df;
        
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return go(n,2);
    }
};