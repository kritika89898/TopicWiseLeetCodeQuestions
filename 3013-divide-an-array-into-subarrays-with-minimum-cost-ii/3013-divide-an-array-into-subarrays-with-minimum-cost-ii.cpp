class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = 0;
        
        multiset<int> bottom, top;
        long long sum_bottom = 0;
        int K = k - 1; // Number of elements we need to pick from the window
        
        // Define the end of the initial window
        int window_end = min(n - 1, dist + 1);
        
        // 1. Populate the initial window
        for (int i = 1; i <= window_end; ++i) {
            bottom.insert(nums[i]);
            sum_bottom += nums[i];
        }
        
        // 2. Rebalance so 'bottom' contains only the smallest K elements
        while (bottom.size() > K) {
            auto it = prev(bottom.end());
            top.insert(*it);
            sum_bottom -= *it;
            bottom.erase(it);
        }
        
        // The cost is always nums[0] + the sum of the best K elements in the window
        ans = sum_bottom + nums[0];
        
        // 3. Slide the window across the rest of the array
        for (int i = window_end + 1; i < n; ++i) {
            int out_val = nums[i - (dist + 1)]; // Element leaving the window
            int in_val = nums[i];               // Element entering the window
            
            // Remove the outgoing element
            auto it_out = bottom.find(out_val);
            if (it_out != bottom.end()) {
                sum_bottom -= *it_out;
                bottom.erase(it_out);
            } else {
                top.erase(top.find(out_val));
            }
            
            // Add the incoming element
            bottom.insert(in_val);
            sum_bottom += in_val;
            
            // Rebalance sizes
            while (bottom.size() > K) {
                auto it_max = prev(bottom.end());
                top.insert(*it_max);
                sum_bottom -= *it_max;
                bottom.erase(it_max);
            }
            
            while (bottom.size() < K) {
                auto it_min = top.begin();
                bottom.insert(*it_min);
                sum_bottom += *it_min;
                top.erase(it_min);
            }
            
            // Ensure all elements in bottom are <= elements in top
            while (!bottom.empty() && !top.empty() && *bottom.rbegin() > *top.begin()) {
                int max_b = *bottom.rbegin();
                int min_t = *top.begin();
                
                // Erase from both sets
                bottom.erase(prev(bottom.end()));
                top.erase(top.begin());
                
                // Swap their places
                bottom.insert(min_t);
                top.insert(max_b);
                
                // Update running sum
                sum_bottom = sum_bottom - max_b + min_t;
            }
            
            // Track the minimum cost found
            ans = min(ans, sum_bottom + nums[0]);
        }
        
        return ans;
    }
};