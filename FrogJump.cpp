#include <bits/stdc++.h>

using namespace std;

class solution
{

public:
    // Simple Recursion Solution
    int frogJump(int n, vector<int> &heights)
    {
        // Write your code here.
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return abs(heights[1] - heights[0]);
        }

        int onestair = frogJump(n - 1, heights);
        int twostair = frogJump(n - 2, heights);

        return min(onestair + abs(heights[n - 1] - heights[n - 2]), twostair + abs(heights[n - 1] - heights[n - 3]));
    }

    // Memoization Solution
    int memFrogJump(int n, vector<int> &heights, vector<int> &dp)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return abs(heights[1] - heights[0]);
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int onestair = memFrogJump(n - 1, heights, dp);
        int twostair = memFrogJump(n - 2, heights, dp);

        if (dp[n] != -1)
        {
            return dp[n];
        }

        return dp[n] = min(onestair + abs(heights[n - 1] - heights[n - 2]), twostair + abs(heights[n - 1] - heights[n - 3]));
    }

    // Tabulation
    int tabFrogJump(int n, vector<int> &heights)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = abs(heights[1] - heights[0]);

        for (int i = 3; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + abs(heights[i - 1] - heights[i - 2]), dp[i - 2] + abs(heights[i - 1] - heights[i - 3]));
        }

        return dp[n];
    }

    // Space Optimized
    int spaFrogJump(int n, vector<int> &heights)
    {
        int prev2 = 0;
        int prev1 = abs(heights[1] - heights[0]);
        int curr = 0;
        for (int i = 3; i <= n; i++)
        {
            curr = min(prev1 + abs(heights[i - 1] - heights[i - 2]), prev2 + abs(heights[i - 1] - heights[i - 3]));
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main()
{

    solution sol;
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();
    // Recursion
    cout << sol.frogJump(n, heights) << endl;
    vector<int> dp(n + 1, -1);
    // Memoization
    cout << sol.memFrogJump(n, heights, dp) << endl;
    // Tabulation
    cout << sol.tabFrogJump(n, heights) << endl;
    // Space Optimized Solution
    cout << sol.spaFrogJump(n, heights) << endl;
    
    return 0;
}
