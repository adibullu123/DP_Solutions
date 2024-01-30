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
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> house_1,house_2;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                house_1.push_back(nums[i]);
                continue;
            }
            if(i==nums.size()-1){
                house_2.push_back(nums[i]);
                continue;
            }
            house_1.push_back(nums[i]);
            house_2.push_back(nums[i]);
        }
        int store1 = spaTab(house_1);
        int store2 = spaTab(house_2);
        return max(store1,store2);
    }
};
