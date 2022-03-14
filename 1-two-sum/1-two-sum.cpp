void swap(vector<int>& nums, int i, int j, int* index) {
	// Swap indices at the same time, to keep track of the original indices.
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    temp = index[i];
    index[i] = index[j];
    index[j] = temp;
}
int partition(vector<int>& nums, int start, int end, int* index) {
	// choose a `random' position
    int p = start + rand()%(end-start);
    swap(nums, p, end, index);
	
	// Now nums[end] is some random value in nums[start, end]
    int r = nums[end];
    int i = start - 1, j = start;
    for(; j < end; j++) {
        if(nums[j]<r) {
            i++;
            swap(nums, i, j, index);
        }
    }
    swap(nums, i+1, end, index);
    return i+1;
}
void quickSort(vector<int>& nums, int start, int end, int* index) {
    if(start<end) {
        int q = partition(nums, start, end, index);
        quickSort(nums, start, q-1, index);
        quickSort(nums, q+1, end, index);        
    }
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int* index = new int[size+1];
		
		// Initialize the origin index to be [0,size)
        for(int i = 0; i < size; i++)
			index[i] = i;
			
		// Sort the vector: nums, and maintain their original indices.
        quickSort(nums, 0, size-1, index);
		
		// Two pointers, start and end, look for two numbers add up to the target.
        int start = 0, end = size-1;
        while(start<end) {
            if(nums[start]+nums[end] == target) break;
            else if(nums[start]+nums[end] < target) start++;
            else end--;
        }
        return vector<int> {index[start], index[end]};
    }
};