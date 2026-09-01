class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> op;
		for(int x=0;x<nums.capacity();x++){
			for(int j=0;j<nums.capacity();j++){
				if(x==j){
					continue;
				}
				if(nums[x]+nums[j]==target){
					op.push_back(x);
					op.push_back(j);
					return op;

				}
			}
		}							   

	return op;
    }
};