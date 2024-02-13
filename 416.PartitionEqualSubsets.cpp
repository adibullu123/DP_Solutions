class Solution {
public:
    // Space Optimization
    bool spa(int n,int target,vector<int> &nums){
        vector<bool> prev(target+1,0);
        //base case
        for(int i=0;i<=target;i++){
            if(i - nums[0]==0){
                prev[i]=1;
            }
            else prev[i]=0;
        }

        for(int i=1;i<n;i++){
            vector<bool> temp(target+1,0);
            for(int j=0;j<=target;j++){
                bool pick = (j>=nums[i])? prev[j-nums[i]]:false;
                bool not_pick = prev[j];

                temp[j] = (pick||not_pick);
            }
            prev = temp;
        }

        return prev[target];
    }
    //Tabulation (recursion stack space eliminated)
    bool tab(int n,int target,vector<int> &nums){
        //create dp vector
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        //base case
        for(int i=0;i<=target;i++){
            if(i - nums[0]==0){
                dp[0][i]=1;
            }
            else dp[0][i]=0;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                bool pick = (j>=nums[i])? dp[i-1][j-nums[i]]:false;
                bool not_pick = dp[i-1][j];

                dp[i][j] = (pick||not_pick);
            }
        }

        return dp[n-1][target];
    }
    // Applied Memoization 
    bool memrecur(int n,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0){
            return true;
        }
        if(n==0){
            if(target-nums[n]==0)return true;
            else return false;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        bool pick = (target>=nums[n])? memrecur(n-1,target-nums[n],nums,dp):false;
        bool not_pick = memrecur(n-1,target,nums,dp);

        return dp[n][target] = (pick||not_pick);
    }
    // BruteForce (AKA no D.P)
    bool recur(int n,int target,vector<int> &nums){
        if(target==0){
            return true;
        }
        if(n==0){
            if(target-nums[n]==0)return true;
            else return false;
        }
        bool pick = (target>=nums[n])? recur(n-1,target-nums[n],nums):false;
        bool not_pick = recur(n-1,target,nums);

        return (pick||not_pick);
    }
    bool canPartition(vector<int>& nums) {
        int numSum = 0;
        for(int i=0;i<nums.size();i++){
            numSum += nums[i];
        }
        if(numSum%2!=0){
            return false;
        }
        int n = nums.size();
        //edge case
        if(n==1){
            return false;
        }
        //dp vector
        int target = numSum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        // return recur(n-1,target,nums);
        // return memrecur(n-1,target,nums,dp);
        // return tab(n,target,nums);
        return spa(n,target,nums);
    }
};
