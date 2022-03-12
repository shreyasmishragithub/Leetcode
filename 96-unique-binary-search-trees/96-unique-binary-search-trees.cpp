class Solution {
public:

    int makeTree(vector<int>& dp,int n) {
        if(n==0) return 1;
        if(n==1 || n==2) return n;
        
        int sum = 0;
        if(dp[n]!=-1) return dp[n];
        
        for(int i=1;i<=n;i++) {
            
            sum+=(makeTree(dp, i-1) * makeTree(dp, n-i));
        }
        dp[n] = sum;
        return dp[n];
    }
    int numTrees(int n) {
        vector<int> dp(20,-1);

        dp[n] = makeTree(dp, n);
        return dp[n];
        
    }
};