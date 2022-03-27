class Solution {
public:
    void go(vector<int>&nums,int idx,int n,int last,int ns11){
        if(idx==n){
            return;
        }
        if((nums[idx]!=last)||(nums[idx]==last&&ns11%2==1)){
            go(nums,idx+1,n,nums[idx],ns11+1);
        }else{
            nums[idx]=-1;
            go(nums,idx+1,n,last,ns11);
        }
    }
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        go(nums,0,n,-1,-1);
        int cnt=0;
        for(auto it:nums){
          //  cout<<it<<" ";
            if(it==-1){
                cnt++;
            }
        }
        if((n-cnt)%2==1){
            return cnt+1;
        }else{
            return cnt;
        }
        
    }
};