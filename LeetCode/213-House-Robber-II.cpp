class Solution {
public:
    int _helper(vector<int>& nums){
        int first = 0;
        int second = 0;
        for (int n: nums){
            int newNum = max(n + first, second);
            first = second;
            second = newNum;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        vector<int> vec1(nums.begin(), nums.end()-1);
        vector<int> vec2(nums.begin() + 1, nums.end());
        return max(nums[0], max(_helper(vec1), _helper(vec2)));
    }
};
