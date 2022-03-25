class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> vec;
        vector<int> tmp(26, 0);
        vec.push_back(tmp);
        for(int i=0; i<s.size(); i++){
            tmp[s[i]-'a']++;
            vec.push_back(tmp);
        }
        
        vector<bool> ans;
        for(auto const& q: queries){
            int lo = q[0], hi = q[1], k = q[2];
            vector<int> cnt = vec[hi+1];
            int odds = 0, sum = 0;
            for(int i=0; i<26; i++){
                cnt[i]-=vec[lo][i];
                sum += cnt[i];
                odds += (cnt[i]%2);
            }
            ans.push_back((odds-=(sum%2))<= k*2?true:false);
            
        }
        return ans;
    }
};