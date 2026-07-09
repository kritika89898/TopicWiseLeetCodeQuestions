class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (first.find(nums[i]) == first.end())
                first[nums[i]] = i;

            last[nums[i]] = i;
            freq[nums[i]]++;
        }

        int degree = 0;
        for (auto &p : freq)
            degree = max(degree, p.second);

        int ans = n;
        for (auto &p : freq) {
            if (p.second == degree) {
                ans = min(ans, last[p.first] - first[p.first] + 1);
            }
        }

        return ans;


    }
};