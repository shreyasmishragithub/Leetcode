class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int mxod=INT_MIN;
        int ans=0;
        int id=min(k,(int)nums.size());
        for(int i=0;i<id-1;i++){
            if(i%2){
                mxod=max(mxod,nums[i]);
                
            }else{
                mxod=max(mxod,nums[i]);
            }
        }
        if(k+0>=(nums.size()-2)){
            ans=nums[nums.size()-2];
        }
        if(k-nums.size()>1){
            ans=nums[nums.size()-1];
        }
        if(nums.size()==1){
            if(k%2){
                return -1;
            }
        }
        if(k%2==0){
            if(k<nums.size()){
                ans=nums[k];
            }
            ans=max(ans,mxod);
        }else if(k%2==1){
            if(k<nums.size()){
                ans=nums[k];
            }
            ans=max(ans,mxod);
        }
        return ans;
    }
};