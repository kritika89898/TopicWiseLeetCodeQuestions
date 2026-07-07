class Solution {
public:
    long long sumAndMultiply(int n) {
        long long newn = 0;
        long long s = 0;
        while(n>0){
            int digit = n%10;
            if(digit != 0){
                newn = newn*10+digit;
                s = s+digit;
            }
            n = n/10;
        }
        string str = to_string(newn);
        reverse(str.begin(),str.end());
        newn = stoi(str);
        return newn*s;

    }
};