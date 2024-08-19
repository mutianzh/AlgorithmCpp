
//Backtrace with memory
// Time O(n^2), Mem O(n^2)
class Solution {
public:
    vector<vector<int>> cache;
    int _helper(int n, int count, int paste){
        if (count == n) {return 0;}
        if (count > n) {return 1001;}

        if (cache[count][paste] != -1) {return cache[count][paste];}
        // If paste directly
        int result1 = 1 + _helper(n, count + paste, paste);
        // if copy and paste
        int result2 = 2 + _helper(n, count * 2, count);

        cache[count][paste] = min(result1, result2);
        return cache[count][paste];
    }

    int minSteps(int n) {
        if (n == 1) {return 0;}
        cache = vector<vector<int>>(n+1, vector<int>(n/2 + 1, -1));
        return 1 + _helper(n, 1, 1);
    }
};

// DP
// Time O(n^2), Mem O(n)
class Solution {
public:
    int minSteps(int n) {
        if (n==1) {return 0;}
        vector<int> dp(n+1, 1001);
        dp[1] = 0;
        for (int i=2; i < n+1; i++){
            for (int j=1; j < n/2 + 1 ; j++){
                if (i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i/j);
                }
            }
        }
        return dp[n];
    }
};

