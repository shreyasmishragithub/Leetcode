class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int i=0;
	int n=nums.size();
	while(i<n){
		int current=nums[i];
		if(current <=0 || current>=n) {
			i++;
			continue;
		}
		if(current!=nums[current-1]){
			int temp = nums[i];
			nums[i]=nums[current-1];
			nums[current-1]= temp;
		}
		else{
			i++;
		}
	}
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;

    }
};