class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> ans;
        sort(arr1.begin(),arr1.end());
        vector<int> used(n, 0);
        int i = 0;
        while(i != m){
            for(int j = 0 ; j < n ; j++){
                if(arr1[j] == arr2[i]){
                    ans.push_back(arr1[j]);
                    used[j] = 1;
                }
            }
            i++;
        }
        for(int i = 0 ; i < n ; i++){
            if(used[i] != 1){
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }
};