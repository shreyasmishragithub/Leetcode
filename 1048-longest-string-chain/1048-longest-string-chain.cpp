class Solution {
public:
       int dp[1001];
    bool static comp(string s1,string s2){
        
        return s1.length()<s2.length();
    }
    
    bool isValid(string &s,string &t){
        
        if(t.size()-s.size()>1 or t.size()==s.size()) return false;
        int n=t.size();
        for(int i=0;i<t.size();i++){
            
            string temp=t.substr(0,i)+t.substr(i+1,n-i-1);
            
            if(temp==s) return true;
        }
        return false;
    }
    
    int helper(int idx,vector<string>&words){
        
        if(dp[idx]!=-1) return dp[idx];
        int n=words.size();
        int ans=1;
        for(int i=idx+1;i<n;i++){
            
            if(isValid(words[idx],words[i])){
                
                ans=max(ans,1+helper(i,words));
                
            }
        }
        return dp[idx]=ans;
    }
    
    int longestStrChain(vector<string>& words) {
        
         memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
          int resmax=1;
        
    
           int n=words.size();
         for(int i=0;i<n;i++){
             
          
             
             resmax=max(resmax,helper(i,words));
         }
        return resmax;
    }
};