class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, used, cur, ans);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, cur, ans);
        return ans;
    }
};