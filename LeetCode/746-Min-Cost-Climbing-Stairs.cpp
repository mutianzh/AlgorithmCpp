class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) {return cost[0];}
        if (n == 2) {return min(cost[0], cost[1]);}
        int first = 0;
        int second = 0;
        for (int i=2; i < n; i++){
            int cur = min(first + cost[i-2], second + cost[i-1]);
            first = second;
            second = cur;
        }
        return min(first + cost[n-2], second + cost[n-1]);
    }
};
