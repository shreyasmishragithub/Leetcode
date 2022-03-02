class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx=0;
        if(!t.length()&&!s.length()){
            return true;
        }
        for(int i=0;i<t.length();i++){
            if(t[i]==s[idx]){
                idx++;
            }
            if(idx==s.length()){
                return true;
            }
        }
        return false;
    }
};