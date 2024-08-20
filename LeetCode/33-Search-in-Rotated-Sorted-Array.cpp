class Solution {
public:
    int _helper(int l, int r, int target, vector<int>& nums){
        if (r < l) {return -1;}
        int label;
        int mid = (l + r) / 2;
        if (nums[l] < nums[r]) {label = 0;} // The array is monotonic
        else if (nums[mid] < nums[r]) {label = -1;} // break at the left
        else {label = 1;} // break at the right

        if (nums[mid] == target) {return mid;}
        else if (nums[mid] < target) {
            if (label == 0) {
                return _helper(mid + 1, r, target, nums);
            } else if (label == -1) {
                if (target <= nums[r]) {return _helper(mid + 1, r, target, nums);}
                else {return _helper(l, mid - 1, target, nums);}
            } else {
                return _helper(mid + 1, r, target, nums);
            }
        } else {
            if (label == 0) {
                return _helper(l, mid - 1, target, nums);
            } else if (label == -1) {
                return _helper(l, mid - 1, target, nums);
            } else {
                if (nums[l] <= target) {
                    return _helper(l, mid - 1, target, nums);
                } else {
                    return _helper(mid + 1, r, target, nums);
                }
            }
        }
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        return _helper(l, r, target, nums);
    }
};
