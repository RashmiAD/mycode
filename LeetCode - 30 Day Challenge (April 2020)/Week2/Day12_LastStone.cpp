// Solution 1 with O(NlogN) time complexity using sorting

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end(), greater<int>());
        int len = stones.size();
        
        while(len > 1){
            stones[0] = stones[0] - stones[1];
            stones[1] = 0;
            sort(stones.begin(), stones.end(), greater<int>());
            len--;
        }
        
        return stones[0];
    }
};

// Solution 2 with O(NlogN) time complexity using MaxHeap but takes less time compared to Solution 1
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
       
        while (stones.size() > 1) 
        {
            int y = stones.front(); //[stones.size() - 1];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int x = stones.front(); //[stones.size() - 1];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            if (x != y) {
                stones.push_back(y - x);
                push_heap(stones.begin(), stones.end());
            } 
        } 
        
        return accumulate(stones.begin(), stones.end(), 0); // if size is zero then need to accumulate the values
    }
};
