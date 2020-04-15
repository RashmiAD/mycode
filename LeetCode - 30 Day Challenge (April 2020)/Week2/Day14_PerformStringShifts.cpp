// Solution 1 - this is simple but involves more string shifts thus the time complexity is O(N*L) where L is the length of the string
// String is immutable i.e. once the string objects is created it cannot be modified. 
// Instead a new string must be created if we want to change it.
// This makes string modification a very expensive operation  at O(L)

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(auto &x : shift)
        {
            if(x[0] == 0)
            {
                rotate(s.begin(), s.begin() + x[1], s.end());
            }
            else
            {
                rotate(s.begin(), s.begin() + s.length() - x[1], s.end());
            }
        }
        
        return s;
    }
};

// Solution 2 - This takes into consideration the operations to be peformed on string. Thus the time complexity is O(N)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int no_of_shifts = 0;
        bool is_right_shift = false;
        
        for(auto &x : shift)
        {
            if(x[0] == 0)
                no_of_shifts += x[1];
            else
                no_of_shifts -= x[1];
        }
        
        if(no_of_shifts < 0)
            is_right_shift = true;
        
        no_of_shifts = abs(no_of_shifts) % s.length();
        
        if(is_right_shift)
            rotate(s.begin(), s.begin() + s.length() - no_of_shifts, s.end());
        else
            rotate(s.begin(), s.begin() + no_of_shifts, s.end());
        
        
        return s;
    }
};
