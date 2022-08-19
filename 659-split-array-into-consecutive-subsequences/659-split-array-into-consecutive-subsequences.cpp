class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {    // Edge Case #1
            return false;
        }
        
        vector<pair<int,int>> v = {{nums[0],1}};
        
        for (int i = 1; i < n; i++) {
            int sz = v.size();
            pair<int,int> end = v[sz-1];
            
            if (nums[i] == end.first+1) {
                v[sz-1].first++;
                v[sz-1].second++;
            }
            else if (nums[i] == end.first) {   // Edge Case #2
                bool found = false;
                for (int k = sz-2; k >= 0; k--) {
                    if (nums[i] == v[k].first+1) {
                        found = true;
                        v[k].first++;
                        v[k].second++;
                        break;
                    }
                }
                if (!found) {
                    v.push_back({nums[i],1});    
                }
            }
            else {
                v.push_back({nums[i],1});
            }
        }
        
        for (auto &it: v) {
            if (it.second < 3) {
                return false;
            }
        }
        return true;
    }
};
