// Sol 1: recursion with memorization
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

//Sol 2: table only
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


// Sol 3: O(1) space
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {return 1;}
        else {
            int prev_prev = 1;
            int prev = 1;
            int cur = 0;
            for (int i=2; i <= n; i++){
                cur = prev_prev + prev;
                prev_prev = prev;
                prev = cur;
            }
            return cur;
        }

    }
};
