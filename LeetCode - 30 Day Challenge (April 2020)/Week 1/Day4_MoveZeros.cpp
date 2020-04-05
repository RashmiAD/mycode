// Though the time complexity is O(n) and space complexity is O(1) but it still takes more operations to perform move,
thus follow the Solution2 for less operations

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                if(index != i) 
                    nums[index] = nums[i];
                index++;
            }
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};

// This Solution2 involves less operations having O(n) time complexity and O(1) space complexity

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[index++], nums[i]);
            }
        }
    }
};
