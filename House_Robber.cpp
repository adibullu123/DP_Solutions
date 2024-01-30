class Solution {
public:

    //Space Optimized
    int spaTab(vector<int>& nums) {
        int n = nums.size();

        int prev2 = nums[0];
        int prev1 = nums[0];
        if(n>1)
        prev1 = max(nums[0],nums[1]);
        int curr = 0;

        for (int i = 2; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;

            curr = max(pick,notPick);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // Tabulation
    int maxTab(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];
        if(n>1){
            dp[1]=max(nums[0],nums[1]);
        }
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i-2];
            int notPick = 0 + dp[i-1];

            dp[i] = max(pick,notPick);
        }

        return dp[n-1];
    }

    // Memoization
    int maxMem(int index, vector<int>& nums, vector<int>& dp) {

        if (index < 0) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int pick = nums[index] + maxMoney(index - 2, nums);
        int notPick = 0 + maxMoney(index - 1, nums);

        return dp[index] = max(pick, notPick);
    }

    // Recursive Solution
    int maxMoney(int index, vector<int>& nums) {

        if (index < 0) {
            return 0;
        }
        int pick = nums[index] + maxMoney(index - 2, nums);
        int notPick = 0 + maxMoney(index - 1, nums);

        return max(pick, notPick);
    }

    // Calling Function
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        // maxMem(nums.size() - 1, nums, dp);
        return spaTab(nums);
    }
};
