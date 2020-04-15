// Solution without division and time complexity O(N) and space complexity O(1) excluding space for output array 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
        output[0] = 1;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            output[i + 1] = output[i] * nums[i];
        }
        
        int R = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            output[i] = output[i] * R; 
            R = R * nums[i];
        }
        
        return output;
    }
};
