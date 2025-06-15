class Solution {
public:
    // Recursive helper function
    // s     -> input binary string
    // i     -> current index
    // prev  -> previous value (0 or 1) in the constructed monotone increasing string
    int hlo(string s, int i, int prev)
    {
        // Base case: if we've processed the entire string, no more flips are needed
        if (i >= s.length())
            return 0;

        int first = INT_MAX;
        int second = INT_MAX;

        // If the previous character is 0, we can keep 0 or flip to 1
        if (prev == 0)
        {
            if (s[i] == '0')
            {
                // Option 1: keep it 0, no flip needed
                first = hlo(s, i + 1, 0);

                // Option 2: flip it to 1
                second = 1 + hlo(s, i + 1, 1);
            }
            else // s[i] == '1'
            {
                // Option 1: flip it to 0
                first = 1 + hlo(s, i + 1, 0);

                // Option 2: keep it 1
                second = hlo(s, i + 1, 1);
            }

            // Return the minimum of the two options
            return min(first, second);
        }
        else
        {
            // If previous is 1, the rest must also be 1 (monotone increasing)
            if (s[i] == '1')
            {
                // No flip needed
                first = hlo(s, i + 1, 1);
            }
            else // s[i] == '0'
            {
                // Must flip it to 1
                second = 1 + hlo(s, i + 1, 1);
            }

            return min(first, second);
        }
    }

    // Main function to find the minimum number of flips
    int minFlipsMonoIncr(string s) {
        // Start processing from index 0 with previous digit as 0
        return hlo(s, 0, 0);
    }
};
