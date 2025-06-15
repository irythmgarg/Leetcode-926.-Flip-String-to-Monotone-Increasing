class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        if (n == 1)
            return 0; // A single character is always monotone increasing

        vector<int> dp(n, 0); // dp[i] stores min flips needed to make s[0..i] monotone increasing
        dp[0] = 0;

        // Count of 1's seen so far (used to decide whether to flip 0s or 1s)
        int ones = s[0] == '0' ? 0 : 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                // No flip needed for '1' if string is still increasing
                dp[i] = dp[i - 1];
                ones++; // Count this '1'
            } else {
                // Two options:
                // 1. Flip current '0' to '1' → 1 + dp[i-1]
                // 2. Flip all previous '1's to '0's → ones
                dp[i] = min(ones, 1 + dp[i - 1]);
            }
        }

        // Final answer is the minimum flips to make entire string monotone increasing
        return dp[n - 1];
    }
};
