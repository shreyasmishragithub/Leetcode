class Solution {
public:
    
    int go(int m,int n,int idx,string a){
         
     if(m==0){        
         return 1;
     } 
        int ans=0;
        for(int i=idx;i<a.length();i++){
            
            ans=ans+go(m-1,n,i,a);
            
        }
        return ans;
    }
    int countVowelStrings(int n) {
        string a="aeiou";
        string t="";
        return go(n,n,0,a);
    }
};