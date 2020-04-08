class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> s;
        int count = 0;
        
        for(int num : arr)
            s.insert(num);
        
        for(int num : arr)
        {
            if(s.find(num + 1) != s.end())
                count++;
        }
        
        return count;
    }
};
