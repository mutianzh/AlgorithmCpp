class Solution {
public:
    int climbStairs(int n, std::vector<int>& memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo[n] == 0) {
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n) {
        std::vector<int> memo(n+1, 0);
        return climbStairs(n, memo);
    }
};
