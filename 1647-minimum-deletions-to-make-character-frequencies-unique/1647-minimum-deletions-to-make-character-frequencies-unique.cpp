class Solution {
public:
    int minDeletions(string s) {
        vector<int> w(26,0);
        for(auto ch:s){
            w[ch-'a']++;
        }
        int cnt = 0;
        sort(w.begin(),w.end());
        unordered_set<int> used;
        for(int p:w){
            while(p>0 && used.count(p)){
                p--;
                cnt++;
            }
            if(p>0) used.insert(p);
        }
        return cnt;
    }
};