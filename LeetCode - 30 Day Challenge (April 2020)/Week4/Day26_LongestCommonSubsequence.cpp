// Solution 1 - Time complexity O(N * M) Space complexity O(N * M)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp[0][0])*(m+1)*(n+1));
        
        for(int col = text2.length() - 1; col >= 0; col--) {
            for(int row = text1.length() - 1; row >= 0; row--) {
                if(text1.at(row) == text2.at(col))
                    dp[row][col] = dp[row + 1][col + 1] + 1;
                else
                    dp[row][col] = max(dp[row + 1][col], dp[row][col + 1]);
            }
        }
        
        return dp[0][0];
    }
};


// Solution 2 - Time complexity O(N * M) Space complexity min(O(N), O(M))
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length() > text2.length()) {
            string temp = text1;
            text1 = text2;
            text2 = temp;
        }
        
        vector<int> previous(text1.length() + 1, 0);
        
        for(int col = text2.length() - 1; col >= 0; col--) {
            
            vector<int> current(text1.length() + 1, 0);
            
            for(int row = text1.length() - 1; row >= 0; row--) {
                if(text1.at(row) == text2.at(col))
                    current[row] = previous[row + 1] + 1;
                else
                    current[row] = max(current[row + 1], previous[row]);
            }
            
            previous = current;
        }
        
        return previous[0];
    }
};
