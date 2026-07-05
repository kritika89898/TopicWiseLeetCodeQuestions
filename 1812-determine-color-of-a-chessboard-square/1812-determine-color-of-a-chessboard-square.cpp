class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int one = coordinates[0]-'a'+1;
        int two = coordinates[1];
        if((one + two)%2 == 0){
            return false;
        }
        return true;
    }
};