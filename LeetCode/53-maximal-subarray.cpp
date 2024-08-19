class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];
        for (int value: nums) {
            curSum += value;
            maxSum = max(curSum, maxSum);
            if (curSum < 0) {curSum = 0;}
        }
        return maxSum;

    }
};
