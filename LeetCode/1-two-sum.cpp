class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        int n = nums.size();
        for (int i=0; i<n; i++){
            int complement = target - nums[i];
            if (myMap.find(complement) != myMap.end()) {
                return {i, myMap[complement]};
            }
            myMap[nums[i]] = i;
        }
        return {};
    }
};
