// Solution1 with HashMap, time complexity is O(n) and space complexity is O(n) but little slower than Solution2
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> hashMap;
        hashMap[0] = -1;
        
        int count = 0, max_len = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                count--;
            else
                count++;
            
            if(hashMap.find(count) != hashMap.end())
                max_len = max(max_len, i - hashMap[count]);
            else
                hashMap.insert(pair<int,int>(count, i));
        }
        
        return max_len;
    }
};

// Solution2 with extra array of size (2n + 1), time complexity is O(n) and space complexity is O(n), faster than Solution1
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        
        int arr[2*len + 1];
        
        for(auto &x : arr)
            x = INT_MIN;
        
        arr[len] = -1;
        
        int count = 0, max = 0;
        
        for(int i = 0;i < len; i++)
        {
            if(nums[i] == 0)
                count--;
            else
                count++;
            
            if(arr[len + count] == INT_MIN)
                arr[len + count] = i;
            else
            {
                if(max < (i - arr[len + count]))
                    max = i - arr[len + count];
            }
        }
        
        return max;
    }
};
