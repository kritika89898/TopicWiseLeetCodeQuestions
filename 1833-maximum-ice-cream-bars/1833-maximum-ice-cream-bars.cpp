class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt = 0;
        int total = coins;
        for(auto& c:costs){
            if(c<=total){
                cnt++;
                total = total - c;
            }else{
                break;
            }
        }
        return cnt;
    }
};