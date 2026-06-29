class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k % 2 == 1) return -1;
        if (k == 0) return nums[0];
        if (k == 1) return n > 1 ? nums[1] : -1;
        int mx = *max_element(nums.begin(), nums.begin() + min(n, k - 1));
        if (k < n) mx = max(mx, nums[k]);
        return mx;
    }
};