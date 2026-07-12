class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>& rides,vector<int>&start,int i){
        if(rides.size() == i) return 0;
        if(dp[i] != -1) return dp[i];
        long long skip = solve(rides,start,i+1);
        int end = rides[i][1];

        int next =
            lower_bound(start.begin(), start.end(), end) - start.begin();

        long long profit = (rides[i][1]-rides[i][0]) + rides[i][2];
        long long take = profit + solve(rides,start,next);
        return dp[i] = max(skip,take);
    
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        
        dp.assign(rides.size(),-1);
        vector<int> start;
        for(auto r:rides){
            start.push_back(r[0]);
        }
        return solve(rides,start,0);
    }
};