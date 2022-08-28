class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<vector<string>>v(words.size());
        for(auto it:mp){
            v[it.second].push_back(it.first);
        }
           vector<string>ans;
        for(int i=words.size()-1;i>=0;i--){
            if(v[i].size()>0){
                sort(v[i].begin(),v[i].end());
                for(auto it:v[i]){
                    ans.push_back(it);
                    if(ans.size()==k){
                        return ans;
                    }
                }
            }
        }
        
        return ans;
    }
};