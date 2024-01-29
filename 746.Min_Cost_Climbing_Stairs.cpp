class Solution {
public:
    int minCost(vector<int> & cost,int n){
        // Recursive Solution
        if(n==1 || n==0){
            return 0;
        }
        int onestair = cost[n-1] + minCost(cost,n-1);
        int twostair = cost[n-2] + minCost(cost,n-2);

        return min(onestair,twostair);
    }

    
    int minCostClimbingStairs(vector<int>& cost) {

        //Space Optimized solution
        int n = cost.size();
        int prev1 = 0 , prev2 = 0,curr = 0;

        for(int i=2;i<=n;i++){
            curr = min(cost[i-1] + prev1 , cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
