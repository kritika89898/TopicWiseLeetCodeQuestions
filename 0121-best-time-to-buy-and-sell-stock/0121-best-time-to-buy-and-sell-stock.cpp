class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int pro = 0;
        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i]<mn){
                mn = prices[i];
            }
            pro = max(pro,prices[i]-mn);
        }
        return pro;
    }
};