class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        return l;
    }

    int upperBound(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) r = m;
            else l = m + 1;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lowerBound(nums, target);
        int r = upperBound(nums, target) - 1;

        if (l <= r && l < nums.size() && nums[l] == target) {
            return {l, r};
        }
        return {-1, -1};
    }
};