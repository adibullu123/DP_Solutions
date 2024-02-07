class Solution {
public:
    int targetSumWays(int n,int target,vector<int> &nums,map<pair<int,int>,int>& dp){
        if(n<0 && target==0){
            return 1;
        }
        if(n<0 && target!=0){
            return 0;
        }
        if(dp.find({n,target}) != dp.end()) return dp[{n,target}];
        int pos = targetSumWays(n-1,target - nums[n],nums,dp);
        int neg = targetSumWays(n-1,target + nums[n],nums,dp);
        
        return dp[{n,target}] = pos + neg;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int> dp;
        return targetSumWays(n-1,target,nums,dp);
    }
};
