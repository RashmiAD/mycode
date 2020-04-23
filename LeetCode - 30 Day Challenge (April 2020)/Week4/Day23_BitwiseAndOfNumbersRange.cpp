// Solution 1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m != 0 && n != 0) {
            if(m == n)
                return m;
            
            int expo_m = floor(log2(m));
            int expo_n = floor(log2(n));
        
            if(expo_m == expo_n) {
                int ans = m;
                
                if(n == INT_MAX)
                    n = n - 1;
                
                for(int i = m + 1; i <= n; i++)
                    ans = ans&i;
                
                return ans;
            }
            else
                return 0;
        }
        else
            return 0;
    }
};

// Solution 2 - Right shift till m == n and count the number of shifts then left shift by the count to the modified m
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        
        while(m != n) {
            m = m >> 1;
            n = n >> 1;
            count++;
        }
        
        return m << count;
    }
};

//Solution 3 - Brian Kernighan's algorithm
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m < n) {
            n = n & (n-1);
        }
        
        return m & n;
    }
};
