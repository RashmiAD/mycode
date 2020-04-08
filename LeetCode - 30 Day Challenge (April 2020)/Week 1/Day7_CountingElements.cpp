class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> s;
        int count = 0;
        
        for(auto &&num : arr)
            s.insert(move(num));
        
        for(auto &&num : arr)
        {
            if(s.find(move(num) + 1) != s.end())
                count++;
        }
        
        return count;
    }
};
