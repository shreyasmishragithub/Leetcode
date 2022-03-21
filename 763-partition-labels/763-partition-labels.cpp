class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>cnt(27);
        vector<int>pr(s.length());
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']++;
        }
        vector<int>ans;
        set<char>ss;
        int idx=0;
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']--;
            ss.insert(s[i]);
            int f=0;
            for(auto it:ss){
                if(cnt[it-'a']!=0){
                    f=1;
                }
            }
            if(f==0){
                ss.clear();
                ans.push_back(i-idx+1);
                idx=i+1;
            }
        }
        return ans;
    }
};