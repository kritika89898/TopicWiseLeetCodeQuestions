class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> a;
    int solve(int i,int c){
        if(i>=n){
            return a[c];
        }
        if(i == n-1){
            return max(a[c],a[i]);
        }
        if(dp[i][c] != -1) return dp[i][c];

        int x = max(a[i],a[c])+solve(i+2,i+1);
        int y = max(a[c],a[i+1])+solve(i+2,i);
        int z = max(a[i],a[i+1])+solve(i+2,c);
        return dp[i][c] = min({x,y,z});


    }
    int minCost(vector<int>& nums) {
        n = nums.size();
        a = nums;
        dp.assign(n+1,vector<int>(n+1,-1));
        if(n==1){
            return a[0];
        }
        if(n==2){
            return max(a[0],a[1]);
        }
        return solve(1,0);
    }
};