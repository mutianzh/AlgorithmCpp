// Sol 1
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

//Sol 2
class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> memo(n+1, 0);
        for (int i=0; i <= n; i++) {
            if (i <= 1) {memo[i] = 1;}
            else {
                memo[i] = memo[i-1] + memo[i-2];
            }
        }
        return memo[n];
    }
};
