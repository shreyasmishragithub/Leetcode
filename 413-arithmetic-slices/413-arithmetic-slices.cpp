class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
		if(n<3) return 0;

        int d = nums[1]-nums[0];
        int possibleAP = 0;
        for(int i=2; i<n; i++){
            if(nums[i]==nums[i-1]+d){
                possibleAP++;
            }else{
                possibleAP = 0;
                d = nums[i]-nums[i-1];
            }
            dp[i] = possibleAP;
        }
        
        return accumulate(dp.begin(),dp.end(),0);
    }
};
