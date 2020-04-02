class Solution {
public:
    bool isHappy(int n) {
        int slowIterator = n;
        int fastIterator = sumOfSquares(n);
        
        while(fastIterator != 1 && slowIterator != fastIterator)
        {
            slowIterator = sumOfSquares(slowIterator);
            fastIterator = sumOfSquares(sumOfSquares(fastIterator));
        }
        
        if(fastIterator == 1)
            return true;
        else
            return false;
    }
    
    int sumOfSquares(int val)
    {
        int sum = 0;
        while(val > 0 )
        {
            int digit = val % 10;
            sum += digit * digit;
            val = val / 10;
        }
        
        return sum;
    }
};
