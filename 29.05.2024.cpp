// User function Template for C++

class Solution {
public:
    int findWinner(int n, int x, int y) {
        // Create a DP array of size n+1
        vector<int> dp(n + 1, 0);
        
        // Base case: 0 coins means Geek cannot win
        dp[0] = 0;
        
        // Fill the DP array
        for (int i = 1; i <= n; ++i) {
            // Check if taking 1 coin leaves opponent in a losing state
            if (i >= 1 && dp[i - 1] == 0) dp[i] = 1;
            // Check if taking x coins leaves opponent in a losing state
            else if (i >= x && dp[i - x] == 0) dp[i] = 1;
            // Check if taking y coins leaves opponent in a losing state
            else if (i >= y && dp[i - y] == 0) dp[i] = 1;
            else dp[i] = 0;  // Otherwise, Geek loses
        }
        
        // Return the result for n coins
        return dp[n];
    }
};
