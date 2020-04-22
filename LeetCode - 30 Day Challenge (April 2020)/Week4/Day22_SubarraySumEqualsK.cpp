class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hm = {{0,1}};
        int sum = 0, count = 0;
        
        for(auto &num : nums) {
            sum += num;
            
            if(hm.count(sum - k) > 0) {
                count += hm[sum - k];
            }
            
            hm[sum]++;
        }
        
        return count;
    }
};
