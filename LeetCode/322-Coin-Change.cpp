class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {return 0;}
        if (coins.size() == 0) {return -1;}
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i < amount+1; i++){
            for (int v: coins){
                if (i - v >= 0) {dp[i] = min(dp[i], 1 + dp[i-v]);}
            }
        }
       return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
