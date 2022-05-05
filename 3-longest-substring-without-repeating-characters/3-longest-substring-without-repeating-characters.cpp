class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st=0;int en=0;
        if(s.length()==0){
            return 0;
        }
        set<char>ss;
        int sizes=0;
        map<char,int>cnt;
        for(int i=0;i<s.length();i++){
            en=i;
            ++cnt[s[en]];
            ss.insert(s[i]);
            int sz=en-st+1;
            while(ss.size()!=sz){
                --cnt[s[st]];
                if(cnt[s[st]]==0){
                ss.erase(s[st++]);
                }else{
                st=st+1;
                }
                sz=en-st+1;
            }
            sizes=max(sizes,en-st+1);
            
        }
        return sizes;
    }
};