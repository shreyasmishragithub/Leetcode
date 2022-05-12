class Solution {
public:
    set<vector<int>>s;
    void go(vector<int>&nums,int idx){
        if(idx==nums.size()){
            s.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            go(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        go(nums,0);
        vector<vector<int>>v;
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }
};