class Solution {
public:
    bool hasAllCodes(string s, int k) {
     int steps=pow(2,k);
        // cout<<steps<<endl;
        int x=0;
        set<string>st;
        if(s.length()==1||s.length()==0||k>s.length()){
            return false;
        }
        for(int i=0;i<=s.length()-k;i++){
            
            st.insert(s.substr(i,k));
        }
        if(st.size()==steps){
            x=1;
        }
        return x;
        
    }
};