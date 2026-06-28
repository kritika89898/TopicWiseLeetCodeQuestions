class Solution {
public:
    int percentageLetter(string s, char letter) {
        double n = s.size();
        double cnt = 0;
        for(auto ch: s){
            if(ch == letter){
                cnt++;
            }
        }
        return (cnt/n)*100;
    }
};