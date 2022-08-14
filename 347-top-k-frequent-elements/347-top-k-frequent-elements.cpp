class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        int i=0;
        while(i<k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return ans;
        
    }
};