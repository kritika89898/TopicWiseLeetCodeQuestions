class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
       long long MOD = 1e9 + 7;
        int n = s.length();
        
        vector<long long> nz_vals;
        vector<int> nz_map(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                nz_vals.push_back(s[i] - '0');
                nz_map[i] = nz_vals.size() - 1;
            }
        }
        
        vector<int> right_nz(n, -1);
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0') last = nz_map[i];
            right_nz[i] = last;
        }
        
        vector<int> left_nz(n, -1);
        last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') last = nz_map[i];
            left_nz[i] = last;
        }
        
        int k = nz_vals.size();
        vector<long long> pref_sum(k + 1, 0);
        vector<long long> pref_val(k + 1, 0);
        vector<long long> pow10(k + 1, 1);
        
        for (int i = 0; i < k; i++) {
            pref_sum[i+1] = pref_sum[i] + nz_vals[i];
            pref_val[i+1] = (pref_val[i] * 10 + nz_vals[i]) % MOD;
            pow10[i+1] = (pow10[i] * 10) % MOD;
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = right_nz[q[0]];
            int R = left_nz[q[1]];
            
            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
            } else {
                long long sum_val = pref_sum[R+1] - pref_sum[L];
                int len = R - L + 1;
                
                long long x_val = (pref_val[R+1] - (pref_val[L] * pow10[len]) % MOD) % MOD;
                if (x_val < 0) x_val += MOD;
                
                ans.push_back((x_val * sum_val) % MOD);
            }
        }
        
        return ans;
    }
};