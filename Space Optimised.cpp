class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        if (n == 1)
            return 0; // Only one character → already monotone

        // Space-optimized dynamic programming
        // `prev` stores the previous dp value (dp[i-1])
        int prev = 0;

        // Count of '1's seen so far (used to decide optimal flips)
        int ones = (s[0] == '0') ? 0 : 1;

        // `now` stores the current dp value (dp[i])
        int now = 0;

        // Iterate through the string starting from index 1
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                // If current character is '1', no flip is needed
                // The number of flips stays same as previous state
                now = prev;

                // Increase the count of '1's seen so far
                ones++;
            } else {
                // If current character is '0':
                // Two options:
                // 1. Flip this '0' to '1' → cost = 1 + prev
                // 2. Flip all previous '1's to '0's → cost = ones
                now = min(1 + prev, ones);
            }

            // Update prev for the next iteration
            prev = now;
        }

        // Final answer: minimum flips to make the entire string monotone increasing
        return now;
    }
};
