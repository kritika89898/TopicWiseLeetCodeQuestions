class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sa =arr;
        sort(sa.begin(),sa.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(auto v:sa){
            if(mp.find(v) == mp.end()){
                mp[v] = rank;
                rank++;
            }
        }
        for(int i = 0 ; i < arr.size() ;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};