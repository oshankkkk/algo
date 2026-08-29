
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> op;
		unordered_map<int,int>hash;
        
		for(int x=0;x<nums.size();x++){

			int rem=target-nums[x];

			if(hash.contains(rem)){
					op.push_back(hash[rem]);
					op.push_back(x);
					return op;
			}

			hash[nums[x]]=x;

		}							   
	return op;
    }
};