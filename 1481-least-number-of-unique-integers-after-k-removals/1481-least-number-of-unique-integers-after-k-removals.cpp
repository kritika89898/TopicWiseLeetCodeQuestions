class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(auto x: arr){
            freq[x]++;
        }
        priority_queue<int,vector<int>,greater<int>> hp;
        for(auto x:freq){
            hp.push(x.second);
        }

        while(k>=hp.top() && !hp.empty()){
            k = k-hp.top();
            hp.pop();

        }
        return hp.size();
    }
};