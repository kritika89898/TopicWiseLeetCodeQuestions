class Solution {
public:
    int minFlips(string target) {
        int cnt = 0;
        if(target[0] == '1'){
            cnt = 1;
        }
        for(int i = 1;i<target.size();i++){
            if(target[i] != target[i-1]){
                cnt++;
            }
        }
       return cnt;
    }
};