// Kadane's Algorithm - Dynamic Programming

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int global_max  = nums[0];
        int current_max = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            current_max = max(nums[i], current_max + nums[i]);
            
            global_max = max(current_max, global_max);
        }
        
        return global_max;
    }
};
