#include <bits/stdc++.h>

using namespace std;

class solution
{

public:
    // Simple Recursion Solution
    int minimizeCost(int n, int k, vector<int> &height)
    {
        // Write your code here.
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return abs(height[1] - height[0]);
        }

        int min_i = 0, minCost = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            if (n - i > 0)
            {
                int temp = minimizeCost(n - i, k, height);
                if (temp < minCost)
                {
                    minCost = temp;
                    min_i = n - i;
                }
            }
        }

        return minCost + abs(height[min_i - 1] - height[n - 1]);
    }

    // Memoization Solution
    int mem(int n, int k, vector<int> &height, vector<int> &dp)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n == 2)
        {
            return abs(height[1] - height[0]);
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        int min_i = 0, minCost = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            if (n - i > 0)
            {
                int temp = mem(n - i, k, height, dp);
                if (temp < minCost)
                {
                    minCost = temp;
                    min_i = n - i;
                }
            }
        }

        return dp[n] = minCost + abs(height[min_i - 1] - height[n - 1]);
    }

    // Tabulation
    int tab(int n, int k, vector<int> &height)
    {
        vector<int> dp(n + 1, 0);

        //base case initialization 
        dp[1] = 0;
        dp[2] = abs(height[1] - height[0]);
        for (int i = 3; i <= n; i++)
        {
            int mincost = INT_MAX;

            //finding least cost
            for (int j = 1; j <= k; j++)
            {   
                if (i - j > 0)
                {
                    int temp = abs(height[i-1] - height[i-j-1]) + dp[i-j];
                    if (temp < mincost)
                    {
                        mincost = temp;
                    }
                }
            }

            dp[i] = mincost;
        }
        return dp[n];
    }

    // Space Optimized
    int spa(int n, vector<int> &heights)
    {
        return 0;
    }
};

int main()
{

    solution sol;
    vector<int> heights = {10, 40, 50, 20, 60};
    int n = heights.size();
    int k = 3;
    // Recursion
    cout << sol.minimizeCost(n, k, heights) << endl;
    vector<int> dp(n + 1, -1);
    // Memoization
    cout << sol.mem(n, k, heights, dp) << endl;
    // Tabulation
    cout << sol.tab(n,k, heights) << endl;
    // Space Optimized Solution
    // cout << sol.spa(n,heights) << endl;

    return 0;
}
