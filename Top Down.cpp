class Solution {
public:
    int dp[100001][2]; // dp[i][prev]: stores the minimum flips needed from index i onward with previous value `prev`

    // Recursive function to compute minimum flips
    // s    -> input binary string
    // i    -> current index
    // prev -> previous value (0 or 1) in the constructed monotone increasing string
    int hlo(string &s, int i, int prev)
    {
        // Base case: If we've reached the end of the string, no flips needed
        if (i >= s.length())
            return 0;

        // Return cached result if already computed
        if (dp[i][prev] != -1)
            return dp[i][prev];

        int first = INT_MAX, second = INT_MAX;

        // If the previous character is 0, we can either stay at 0 or move to 1
        if (prev == 0)
        {
            if (s[i] == '0') {
                // No flip needed to stay at 0
                first = hlo(s, i + 1, 0);
                // Flip current 0 to 1
                second = 1 + hlo(s, i + 1, 1);
            }
            else { // s[i] == '1'
                // Flip current 1 to 0
                first = 1 + hlo(s, i + 1, 0);
                // No flip needed to move to 1
                second = hlo(s, i + 1, 1);
            }
            // Store and return the minimum of both options
            return dp[i][prev] = min(first, second);
        }
        else
        {
            // If prev is 1, we must keep all next characters 1 (monotone increasing)

            if (s[i] == '1') {
                // No flip needed
                first = hlo(s, i + 1, 1);
            }
            else {
                // Flip current 0 to 1
                second = 1 + hlo(s, i + 1, 1);
            }
            // Store and return the minimum of both options
            return dp[i][prev] = min(first, second);
        }
    }

    // Main function to initialize DP array and start recursion
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp)); // Initialize dp with -1
        return hlo(s, 0, 0);        // Start from index 0 with previous value 0
    }
};
